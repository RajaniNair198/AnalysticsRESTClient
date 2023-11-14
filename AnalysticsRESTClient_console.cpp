#include <iostream>

#include "connection.h"
#include "restclient.h"

int main()
{
    // initialize RestClient
    RestClient::init();

    // get a connection object
    RestClient::Connection* conn = new RestClient::Connection("https://localhost:44310/");

    // configure basic auth
    //conn->SetBasicAuth("WarMachine68", "WARMACHINEROX");

    // set connection timeout to 5s
    //conn->SetTimeout(5);

    // set custom user agent
    // (this will result in the UA "foo/cool restclient-cpp/VERSION")
    //conn->SetUserAgent("foo/cool");

    // enable following of redirects (default is off)
    conn->FollowRedirects(true);
    // and limit the number of redirects (default is -1, unlimited)
    conn->FollowRedirects(true, 3);

    // set headers
    RestClient::HeaderFields headers;
    headers["Accept"] = "application/json";
    conn->SetHeaders(headers);

    // append additional headers
    conn->AppendHeader("X-MY-HEADER", "AddOns");

    // if using a non-standard Certificate Authority (CA) trust file
    //conn->SetCAInfoFilePath("IntermediateCA.crt");

    conn->SetCAInfoFilePath("non-existent file");
    conn->SetVerifyPeer(false);


    //Testing a simple REST API call
    RestClient::Response r = RestClient::get("https://localhost:44310/api/AddOns");
    RestClient::Response response1 = conn->get("https://localhost:44310/api/Users");
    //RestClient::Response r = conn->get("/get");
    //RestClient::Response r = conn->head("/get");
    //RestClient::Response r = conn->del("/delete");
    //RestClient::Response r = conn->options("/options");

    // set different content header for POST, PUT and PATCH
    conn->AppendHeader("Content-Type", "application/json");
    //RestClient::Response r = conn->post("/post", "{\"foo\": \"bla\"}");
    //RestClient::Response r = conn->put("/put", "application/json", "{\"foo\": \"bla\"}");
    //RestClient::Response r = conn->patch("/patch", "text/plain", "foobar");

    // deinit RestClient. After calling this you have to call RestClient::init()
    // again before you can use it
    RestClient::disable();


}


