#[cxx::bridge]
mod ffi {

    unsafe extern "C++" {
        include!("divisor-rs/include/utils.h");
        type Result;
        fn get_divisor_rs(number: u32) -> UniquePtr<Result>;
        fn get_first_multiplier(result: &Result) -> u32;
        fn get_second_multiplier(result: &Result) -> u32;
    }
}

pub fn get_multiplier(number: u32) -> (u32, u32) {
	let res: cxx::UniquePtr<ffi::Result> = ffi::get_divisor_rs(number);
	
	(ffi::get_first_multiplier(&res), ffi::get_second_multiplier(&res))
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let num: u32 = 24;
        let res: (u32, u32) = get_multiplier(num);
        
        print("num = {} * {}", res.0, res.1);
        
    }
}
