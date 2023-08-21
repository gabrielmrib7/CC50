-- Keep a log of any SQL queries you execute as you solve the mystery.

-- ocorreu em 28 de julho de 2020 na Chamberlin Street as 10:15am

SELECT * from crime_scene_reports where year = "2020" and month = "7" and day = "28" and street = "Chamberlin Street";

 -- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today with three witnesses who were present at the time
 -- — each of their interview transcripts mentions the courthouse.

 SELECT * from interviews where year = "2020" and month = "7" and day = "28";

 -- RUTH: Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
 -- If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame. : ladrao saiu do estacionamento 10 minutos depois do roubo

 -- RAYMOND: As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
 -- The thief then asked the person on the other end of the phone to purchase the flight ticket. ladrao pegou o primeiro voo de fiftyville e pediu para a pessoa comprar a passagem, chamada durou menos de 1 minuto

 -- EUGENE: I don't know the thief's name, but it was someone I recognized.
 -- Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money. ladrao sacou dinheiro nesta manha antes do ato.

 SELECT name from people
 join courthouse_security_logs csl on csl.license_plate = people.license_plate
 where csl.year = "2020" and csl.month = "7" and csl.day = "28" and csl.hour = "10" and csl.minute >="15" and csl.minute <="25" and csl.activity = "exit";

 -- suspeitos:| Patrick   || Ernest    || Amber     || Danielle  || Roger     || Elizabeth || Russell   || Evelyn

 SELECT name from people
 join atm_transactions atm
 join bank_accounts on bank_accounts.account_number = atm.account_number and bank_accounts.person_id = people.id
 where atm.day = "28" and atm.month = "7" and atm.year = "2020" and atm.atm_location = "Fifer Street" and transaction_type = "withdraw";

 -- suspeitos: *Ernest*, *Russel*, *Elizabeth*, *Danielle*, Madison, Victoria, Roy, Bobby.

SELECT name from people
join passengers on passengers.passport_number = people.passport_number
join flights on flights.id = passengers.flight_id
where day = "29" and month = "7" and year = "2020"
and people.phone_number = (SELECT caller from phone_calls
where year = "2020" and day="28" and month="7" and duration < "60" and people.phone_number = phone_calls.caller)
ORDER BY HOUR, MINUTE;

-- ROGER, *ERNEST* (ordenado pela hora ernest foi o primeiro a pegar voo entre os suspeitos logo ele é o ladrão)

Select phone_number from people where name = "Ernest";

SELECT name from people
join phone_calls on people.phone_number = phone_calls.receiver
where day = "28" and month = "7" and year = "2020" and duration < "60" and caller = "(367) 555-5533";

-- O CUMPLICE FOI BERTHOLD

SELECT city from airports
where id = (SELECT destination_airport_id from flights
where day = "29" and month = "7" and year = "2020" order by hour, minute);

-- O LADRAO FOI PARA LONDRES.
