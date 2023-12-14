#include "workflow/WFFacilities.h"
#include <csignal>
#include "wfrest/HttpServer.h"


static 	WFFacilities::WaitGroup wait_group(1);

void sig_handler(int signo) {	wait_group.done(); }

void inital_server()
{
    signal(SIGINT, sig_handler);

    wfrest::HttpServer svr;

    // curl -v http://ip:port/hello
    svr.GET("/hello", [](const HttpReq *req, HttpResp *resp) { resp->String("world\n"); });
    // curl -v http://ip:port/data
    svr.GET("/data", [](const HttpReq *req, HttpResp *resp) { std::string str = "Hello world"; resp->String(std::move(str)); });

    svr.ROUTE("/multi", [](const HttpReq *req, HttpResp *resp) { std::string method(req->get_method()); resp->String(std::move(method)); }, {"GET", "POST"});

    // curl -v http://ip:port/post -d 'post hello world'
    svr.POST("/post", [](const HttpReq *req, HttpResp *resp)
    {
        // reference, no copy here
        std::string& body = req->body(); fprintf(stderr, "post data : %s\n", body.c_str());
    });

    // curl -v http://ip:port/any_path
    svr.set_default_route("/data");

    if (svr.track().start(8888) == 0) { svr.list_routes(); wait_group.wait(); svr.stop();} 
		
		else { fprintf(stderr, "Cannot start server"); exit(1); }

}

void send_json()
{
    signal(SIGINT, sig_handler);

    wfrest::HttpServer svr;

    // curl -v http://ip:port/json1
    svr.GET("/json1", [](const HttpReq *req, HttpResp *resp) { Json json; json["test"] = 123; json["json"] = "test json"; resp->Json(json); });

    // curl -v http://ip:port/json2
    svr.GET("/json2", [](const HttpReq *req, HttpResp *resp)
    {
        std::string valid_text = R"( { "numbers": [1, 2, 3] } )";
        resp->Json(valid_text);
    });

    // curl -v http://ip:port/json3
    svr.GET("/json3", [](const HttpReq *req, HttpResp *resp)
    {
        std::string invalid_text = R"( { "strings": ["extra", "comma", ] } )";
        resp->Json(invalid_text);
    });

    // recieve json
    //   curl -X POST http://ip:port/json4
    //   -H 'Content-Type: application/json'
    //   -d '{"login":"my_login","password":"my_password"}'
    svr.POST("/json4", [](const HttpReq *req, HttpResp *resp)
    {
        if (req->content_type() != APPLICATION_JSON) { resp->String("NOT APPLICATION_JSON"); return; } fprintf(stderr, "Json : %s", req->json().dump(4).c_str());
    });

    if (svr.start(8888) == 0) { wait_group.wait(); svr.stop(); } 

		else { fprintf(stderr, "Cannot start server"); exit(1); }
    
}


void main -> int ()

{
		if (1 = 1)	inital_server() ;
		if (1 = -1)  send_json() ;
		// line 
		return 0 ;
}
