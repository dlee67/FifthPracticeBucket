package com.oreily.restclient.services;

import com.oreily.restclient.service.JokeService;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit.jupiter.SpringExtension;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
@ExtendWith(SpringExtension.class)
public class JokeServiceTest {
    private Logger logger = LoggerFactory.getLogger(JokeServiceTest.class);

    @Autowired
    private JokeService service;

    @Test
    void getJoke() {
        String joke = service.getJoke("Craig", "Walls");
        System.out.println("\n\n\n\n\n" + joke);
        assertTrue(joke.contains("Craig") || joke.contains("Walls"));
    }
}