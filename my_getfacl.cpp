#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/xattr.h>
#include <grp.h>
#include <pwd.h>

void print_acl(const char *path) {
    // Get file information using stat
    struct stat file_stat;
    if (stat(path, &file_stat) == -1) {
        perror("stat");
        return;
    }

    // Display file name, owner, and group
    std::cout << "# file: " << path << std::endl;
    std::cout << "# owner: " << getpwuid(file_stat.st_uid)->pw_name << std::endl;
    std::cout << "# group: " << getgrgid(file_stat.st_gid)->gr_name << std::endl;

    // Display setuid, setgid, and sticky bits
    std::cout << "# flags: ";
    if (file_stat.st_mode & S_ISUID) std::cout << "s";
    else std::cout << "-";
    if (file_stat.st_mode & S_ISGID) std::cout << "s";
    else std::cout << "-";
    if (file_stat.st_mode & S_ISVTX) std::cout << "t";
    else std::cout << "-";
    std::cout << std::endl;

    // Get and display ACL using getxattr
    char acl_buffer[4096];
    ssize_t acl_size = getxattr(path, "system.posix_acl_access", acl_buffer, sizeof(acl_buffer));

    if (acl_size == -1) {
        // If there is no ACL, display traditional file mode permissions
        std::cout << "user::" << ((file_stat.st_mode & S_IRUSR) ? "r" : "-") << ((file_stat.st_mode & S_IWUSR) ? "w" : "-") << ((file_stat.st_mode & S_IXUSR) ? "x" : "-") << std::endl;
        std::cout << "group::" << ((file_stat.st_mode & S_IRGRP) ? "r" : "-") << ((file_stat.st_mode & S_IWGRP) ? "w" : "-") << ((file_stat.st_mode & S_IXGRP) ? "x" : "-") << std::endl;
        std::cout << "other::" << ((file_stat.st_mode & S_IROTH) ? "r" : "-") << ((file_stat.st_mode & S_IWOTH) ? "w" : "-") << ((file_stat.st_mode & S_IXOTH) ? "x" : "-") << std::endl;
    } else {
        // Parse and display ACL entries
        char *acl_entry = acl_buffer;
        while (acl_entry < acl_buffer + acl_size) {
            std::cout << acl_entry << std::endl;
            acl_entry += strlen(acl_entry) + 1;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    print_acl(argv[1]);

    return 0;
}
