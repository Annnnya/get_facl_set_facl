#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <sstream>


void modifyPermissions(const std::filesystem::path& path, const std::string& modification) {
    std::filesystem::perms permissions = std::filesystem::status(path).permissions();

    std::istringstream iss(modification);
    std::string option, type, name, access;

    std::getline(iss, option, ':');
    std::getline(iss, type, ':');
    std::getline(iss, name, ':');
    std::getline(iss, access, ':');

    if (option == "-m") {
        if (type == "u") {
            if (access.find('r') != std::string::npos) permissions |= std::filesystem::perms::owner_read;
            if (access.find('w') != std::string::npos) permissions |= std::filesystem::perms::owner_write;
            if (access.find('x') != std::string::npos) permissions |= std::filesystem::perms::owner_exec;
        } else if (type == "g") {
            if (access.find('r') != std::string::npos) permissions |= std::filesystem::perms::group_read;
            if (access.find('w') != std::string::npos) permissions |= std::filesystem::perms::group_write;
            if (access.find('x') != std::string::npos) permissions |= std::filesystem::perms::group_exec;
        }

    } else if (option == "-x") {
        if (type == "u") {
            if (access.find('r') != std::string::npos) permissions &= ~std::filesystem::perms::owner_read;
            if (access.find('w') != std::string::npos) permissions &= ~std::filesystem::perms::owner_write;
            if (access.find('x') != std::string::npos) permissions &= ~std::filesystem::perms::owner_exec;
        } else if (type == "g") {
            if (access.find('r') != std::string::npos) permissions &= ~std::filesystem::perms::group_read;
            if (access.find('w') != std::string::npos) permissions &= ~std::filesystem::perms::group_write;
            if (access.find('x') != std::string::npos) permissions &= ~std::filesystem::perms::group_exec;
        }


    } else if (option == "-p") {
        permissions = std::filesystem::perms::none;

        if (type == "u") {
            if (access.find('r') != std::string::npos) permissions |= std::filesystem::perms::owner_read;
            if (access.find('w') != std::string::npos) permissions |= std::filesystem::perms::owner_write;
            if (access.find('x') != std::string::npos) permissions |= std::filesystem::perms::owner_exec;
        } else if (type == "g") {
            if (access.find('r') != std::string::npos) permissions |= std::filesystem::perms::group_read;
            if (access.find('w') != std::string::npos) permissions |= std::filesystem::perms::group_write;
            if (access.find('x') != std::string::npos) permissions |= std::filesystem::perms::group_exec;
        }
    }
    std::filesystem::permissions(path, permissions);
    std::cout << "Permissions modified for: " << path << std::endl;
}

void recursivePermissions(const std::filesystem::path& path, const std::string& modification) {
    if (std::filesystem::is_directory(path)) {
        for (const auto& entry : std::filesystem::recursive_directory_iterator(path)) {
            if (std::filesystem::is_regular_file(entry)) {
                std::filesystem::path absolutePath = std::filesystem::absolute(entry.path());
                modifyPermissions(absolutePath, modification);
            }
        }
    } else {
        std::filesystem::path absolutePath = std::filesystem::absolute(path);
        modifyPermissions(absolutePath, modification);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: my_setfacl [option] [path]...\n";
        return 1;
    }
    std::string modification = argv[1];
    std::string path = argv[2];

    if (modification == "--help") {
        std::cout << "Usage: ./setfacl [option] [path]...\n";
        std::cout << "-m:[u|g]:[<username>|<groupname>]:[rwx] : Modify permissions\n";
        std::cout << "-x:[u|g]:[<username>|<groupname>] : Remove permissions\n";
        std::cout << "-p:[u|g]:[<username>|<groupname>]:[rwx] : Set new permissions, removing previous ACL\n";
        std::cout << "-R : Recursively traverse directories\n ./setfacl -m:u:root:rwx -R /home/user\n";
        return 0;
    }

    if (argc >= 4 && std::string(argv[3]) == "-R") {
        recursivePermissions(path, modification);
    } else {
        modifyPermissions(path, modification);
    }

    return 0;
}
