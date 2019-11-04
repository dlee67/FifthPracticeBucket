package com.oreily.demo;

import org.junit.jupiter.api.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.context.ApplicationContext;
import org.springframework.test.context.junit4.SpringRunner;

import java.text.NumberFormat;

@RunWith(SpringRunner.class)
@SpringBootTest
class DemoApplicationTests {

	// The below is me asking Spring, "do you have one of these around?
	// If so, plug it in right here."
	// So, it's an dependency injection.
	@Autowired
	private ApplicationContext ctx;

	@Autowired
	@Qualifier("defaultCurrency")
	// Qualifier, in this specific case, is filtering out all the NumberFormat beans,
	// except the Bean named: defaultCurrencyFormat
	// It's similar concept like Butterknife.
	private NumberFormat nf;

	@Test
	public void defaultCurrency() {
		double amount = 12345.12345;
		System.out.println(nf.format(amount));
	}

	@Test
	void contextLoads() {
		int count = ctx.getBeanDefinitionCount();
		System.out.println("There are " + count + " beans in the application context.");
		for(String name : ctx.getBeanDefinitionNames()) {
			System.out.println(name);
		}
	}

	@Test
	public void germanCurrency() {
		double amount = 12345.12345;
		// Since, we have two beans with the same data type, we can't use the nf class variable at the top.
		// I guess, application context is like the Android's Context, that holds all the info about
		// Activities and stuff.
		NumberFormat deutschNF = ctx.getBean("germanCurrency", NumberFormat.class);
		System.out.println(deutschNF.format(amount));
	}

}
