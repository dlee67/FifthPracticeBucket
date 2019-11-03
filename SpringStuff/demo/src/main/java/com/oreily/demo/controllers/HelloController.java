package com.oreily.demo.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class HelloController {

    // I need to use the below annotation if I want to use the HTTP requests.
    @GetMapping("/hello")
    public String sayHello(
            // required = false enables the users to not pass in any arguments.
            // To use the param below, the URL would look like ...
            // http://localhost:8080/hello?name=Wing%20Stop
            @RequestParam(defaultValue = "world", required = false) String name,
            Model model) {
        model.addAttribute("user", name); // Essentially, a map.
        return "hello"; // The left won't actually return the string hello, but the hello.html in templates.
    }
}
