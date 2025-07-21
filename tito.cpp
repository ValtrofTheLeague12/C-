#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>

void test_port(int port) {
    int soc = socket(AF_INET, SOCK_STREAM, 0);
    if (soc == -1) {
        std::cerr << "Socket error: " << strerror(errno) << std::endl;
        return;
    }

    // Allow port reuse
    int opt = 1;
    setsockopt(soc, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in server = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr = {INADDR_ANY}  // 127.0.0.1
				       //
    };

    if (bind(soc, (sockaddr*)&server, sizeof(server)) == 0) {
        listen(soc, 5);  // Required for TCP
        std::cout << "Port " << port << " is OPEN on 127.0.0.1\n";
    } else {
        std::cerr << "Port " << port << " failed: " << strerror(errno) << "\n";
    }
    close(soc);
}

int main() {
    test_port(8080);  // Test a common alt HTTP port
    test_port(3000);  // Test Node.js default port
    return 0;
}
