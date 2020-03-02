# language: en

Feature: Application should be able to print greeting message Hello BDD!

   Scenario: Should be able to greet with Hello BDD! message
      Given an instance of Hello class is created
      When the sayHello method is invoked
      Then it should return "Hello BDD!"