//
//  hello.cc
//
//  Copyright (c) 2019 Yuji Hirose. All rights reserved.
//  MIT License
//

#include "httplib.h"
#include <string>
#include <iostream>

using namespace httplib;
using namespace std;

int main(void) {
  
  string url = "https://sandbox-api.coinmarketcap.com/v1/cryptocurrency/listings/latest";
  string someString = "07ea55d5-5746-48ff-8b89-0ddc03f45907";

  Server svr;

  svr.Get("/hi", [](const Request & /*req*/, Response &res) {
    res.set_content("Hello World!", "text/plain");
  });

  svr.listen("localhost", 1234);
}