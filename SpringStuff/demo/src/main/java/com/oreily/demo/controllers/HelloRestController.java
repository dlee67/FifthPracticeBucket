package com.oreily.demo.controllers;

import com.oreily.demo.entities.Greeting;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloRestController {

    // The entire thing below is a RESTful webservice.
    @GetMapping("/rest")
    public Greeting greet(@RequestParam(defaultValue = "World",
                            required = false) String name){
        // return new Greeting("Hello, " + name +  "!"); Apparently, this is very 2002.
        return new Greeting(String.format("Hello, %s!", name)); // Returns the JSON object upon request GET on /rest.
    }
}