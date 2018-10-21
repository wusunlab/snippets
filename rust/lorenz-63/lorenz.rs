// Lorenz 63 model

fn main() {
    const RHO: f64 = 10.0;  // Prandtl number
    const SIGMA: f64 = 8.0 / 3.0;  // Rayleigh number
    const BETA: f64 = 28.0;

    let (mut x, mut y, mut z) = (1.0, 1.0, 1.0);  // position
    let (mut dx, mut dy, mut dz);  // changes in position
    let dt = 1e-3;  // time step

    println!("Lorenz 63 model");
    println!("Prandtl number = {:?}", RHO);
    println!("Rayleigh number = {:.8}", SIGMA);
    println!("beta = {:?}", BETA);
    println!("The initial state is at [{:?}, {:?}, {:?}]", x, y, z);

    // forward Euler scheme
    for i in 1..100 {
        dx = SIGMA * (y - x);
        dy = x * (RHO - z) - y;
        dz = x * y - BETA * z;
        x += dt * dx;
        y += dt * dy;
        z += dt * dz;
        println!("t = {:.3}, [{:.8}, {:.8}, {:.8}]", i as f64 * dt, x, y, z)
    }
}
