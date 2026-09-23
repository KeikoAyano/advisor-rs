use divisor_rs::get_multiplier;

fn main() {
    let number: u32 = 24;

    let res = get_multiplier( number );

    println!("{} = {} * {}", number, res.0, res.1 );
}

