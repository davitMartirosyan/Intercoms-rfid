#include <iostream>
#include <vector>
// #include <boost/asio.hpp>
#include <asio.hpp>
// using namespace boost::asio;
// using ip::tcp;
// using std::string;
// using std::cout;
// using std::endl;

// typedef struct s_conn
// {
//     uint8_t start;  // 0XEF
//     char imei[15]; // imei code
//     uint8_t end;  // 0XEE
// }t_conn;

// string read_(tcp::socket & socket)
// {
//     boost::asio::streambuf buf;
//     boost::asio::read_until(socket, buf, 0xEE);
//     string data = boost::asio::buffer_cast<const char*>(buf.data());
//     return data;
// }

// void send_(tcp::socket & socket, const string& msg)
// {
//     const string mess = msg + "\n";
//     boost::asio::write(socket, boost::asio::buffer(msg));
// }

// int main()
// {
//     boost::asio::io_service io_service;
//     tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 8080));
//     tcp::socket socket_(io_service);
//     acceptor_.accept(socket_);
//     string msg = read_(socket_);
//     cout << msg << endl;
//     send_(socket_, "Hello form server");
//     cout << "Servent sent Hello message to Client!" << endl;
//    return 0;
// }