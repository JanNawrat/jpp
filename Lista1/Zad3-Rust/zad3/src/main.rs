use rust_library;
use std::io;
use std::process;

fn read_number() -> i64 {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");
    return input.trim().parse().expect("Please type a number!");
}

fn main() {
    let mut option : u8;
    let mut a : i64;
    let mut b : i64;
    let mut c : i64;
    let mut result : u64;

    println!("Library in Rust");
    loop {
        println!("1. Factorial loop\n2. Factorial recursive\n3. GCD loop\n4. GCD recursive\n5. Diophantic loop\n6. Diophantic recursive\n7. Exit");
        option = read_number() as u8;

        match option {
            1 => {
                println!("Input n");
                a = read_number();
                result = rust_library::factorial_loop(a as u64);
                println!("Result: {result}");},
            2 => {
                println!("Input n");
                a = read_number();
                result = rust_library::factorial_recursive(a as u64);
                println!("Result: {result}");},
            3 => {
                println!("Input a");
                a = read_number();
                println!("Input b");
                b = read_number();
                result = rust_library::gcd_loop(a as u64, b as u64);
                println!("Result: {result}");},
            4 => {
                println!("Input a");
                a = read_number();
                println!("Input b");
                b = read_number();
                result = rust_library::gcd_recursive(a as u64, b as u64);
                println!("Result: {result}");},
            5 => {
                println!("Input x");
                a = read_number();
                println!("Input y");
                b = read_number();
                println!("Input c");
                c = read_number();
                (option, a, b) = rust_library::diophantic_loop(a, b, c);
                if option == 0 {
                    println!("Reult: x = {a}, y = {b}");
                } else if option == 1 {
                    println!("No results");
                } else if option == 2 {
                    println!("Infinite number of results");
                } else {
                    println!("Error");
                }},
            6 => {
                println!("Input x");
                a = read_number();
                println!("Input y");
                b = read_number();
                println!("Input c");
                c = read_number();
                (option, a, b) = rust_library::diophantic_recursive(a, b, c);
                if option == 0 {
                    println!("Reult: x = {a}, y = {b}");
                } else if option == 1 {
                    println!("No results");
                } else if option == 2 {
                    println!("Infinite number of results");
                } else {
                    println!("Error");
                }},
            7 => process::exit(0),
            _ => {}
        }
    }
}
