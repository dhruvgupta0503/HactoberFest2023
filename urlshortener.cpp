extern crate rand;

use rand::Rng;

fn main() {
    // Generate random weather data
    let temperature = rand::thread_rng().gen_range(0..100);
    let humidity = rand::thread_rng().gen_range(0..100);
    let wind_speed = rand::thread_rng().gen_range(0..50);
    let pressure = rand::thread_rng().gen_range(970.0..1030.0);

    // Perform a simple storm prediction
    let is_storm_coming = predict_storm(temperature, humidity, wind_speed, pressure);

    // Display the results
    println!("Temperature: {}°C", temperature);
    println!("Humidity: {}%", humidity);
    println!("Wind Speed: {} km/h", wind_speed);
    println!("Pressure: {} hPa", pressure);

    if is_storm_coming {
        println!("Warning: A storm might be coming!");
    } else {
        println!("No storm in the forecast.");
    }
}

fn predict_storm(temperature: u32, humidity: u32, wind_speed: u32, pressure: f64) -> bool {
    // Define arbitrary thresholds for each parameter.
    // In practice, these values should be based on real data and expert analysis.
    let temperature_threshold = 30;
    let humidity_threshold = 80;
    let wind_speed_threshold = 50;
    let low_pressure_threshold = 975.0;
    let high_pressure_threshold = 1025.0;

    // Check if the conditions meet the storm criteria.
    if temperature > temperature_threshold
        && humidity > humidity_threshold
        && wind_speed > wind_speed_threshold
        && (pressure < low_pressure_threshold || pressure > high_pressure_threshold)
    {
        return true; // A storm might be coming.
    }

    false // No storm in the forecast.
}
