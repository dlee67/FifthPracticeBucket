package com.oreily.demo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

import java.text.NumberFormat;
import java.util.Locale;

@SpringBootApplication
public class DemoApplication {

	public static void main(String[] args) {
		SpringApplication.run(DemoApplication.class, args);
	}

	// I am going to add my own Bean.
	@Bean // The name of the method will become Bean's name.
	public NumberFormat defaultCurrency() {
		return NumberFormat.getCurrencyInstance();
	}

	@Bean
	public NumberFormat germanCurrency() {
		return NumberFormat.getCurrencyInstance(Locale.GERMANY);
	}
}
