#include "httplib.h"
#include "inja.hpp"
#include "json.hpp"

using namespace std;
using namespace httplib;
using json = nlohmann::json;

int main() {
    Server svr;
    inja::Environment env;
    string html_template = env.load_file("templates/index.html");

    svr.Get("/", [=, &env](const Request& req, Response& res) {
        json data;
        data["title"] = "Inja Example";
        data["name"] = "Ilia Petrov";

        string result = env.render(html_template, data);
        res.set_content(result, "text/html");
    });

    cout << "Server is running on port 8080" << endl;
    svr.listen("localhost", 8080);
    return 0;	
}
