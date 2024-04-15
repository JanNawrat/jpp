use rust_wrapper;
use std::io;
use std::process;

fn read_number() -> i32 {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");
    return input.trim().parse().expect("Please type a number!");
}

fn main() {
    let mut option : u8;
    let mut a : i32;
    let mut b : i32;
    let mut c : i32;
    let mut result : i32;

    println!("Library in Rust");
    loop {
        println!("1. Factorial loop\n2. Factorial recursive\n3. GCD loop\n4. GCD recursive\n5. Diophantic loop\n6. Diophantic recursive\n7. Exit");
        option = read_number() as u8;

        match option {
            1 => {
                println!("Input n");
                a = read_number();
                result = rust_wrapper::factorial_loop_wrapper(a);
                println!("Result: {result}");},
            2 => {
                println!("Input n");
                a = read_number();
                result = rust_wrapper::factorial_recursive_wrapper(a);
                println!("Result: {result}");},
            3 => {
                println!("Input a");
                a = read_number();
                println!("Input b");
                b = read_number();
                result = rust_wrapper::gcd_loop_wrapper(a, b);
                println!("Result: {result}");},
            4 => {
                println!("Input a");
                a = read_number();
                println!("Input b");
                b = read_number();
                result = rust_wrapper::gcd_recursive_wrapper(a, b);
                println!("Result: {result}");},
            5 => {
                println!("Input x");
                a = read_number();
                println!("Input y");
                b = read_number();
                println!("Input c");
                c = read_number();
                (c, a, b) = rust_wrapper::diophantic_loop_wrapper(a, b, c);
                if c == 0 {
                    println!("Reult: x = {a}, y = {b}");
                } else if c == 1 {
                    println!("No results");
                } else if c == 2 {
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
                (c, a, b) = rust_wrapper::diophantic_recursive_wrapper(a, b, c);
                if c == 0 {
                    println!("Reult: x = {a}, y = {b}");
                } else if c == 1 {
                    println!("No results");
                } else if c == 2 {
                    println!("Infinite number of results");
                } else {
                    println!("Error");
                }},
            7 => process::exit(0),
            _ => {}
        }
    }
}
