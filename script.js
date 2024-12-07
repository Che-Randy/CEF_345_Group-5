document.getElementById("calculate-fare").addEventListener("click", () => {
    const rideType = document.getElementById("ride-type").value;
    const baseFare = 50; // Base fare for all rides
    let multiplier = 1;

    // Adjust multiplier based on ride type
    switch (rideType) {
        case "economy":
            multiplier = 1;
            break;
        case "standard":
            multiplier = 1.5;
            break;
        case "luxury":
            multiplier = 2;
            break;
        default:
            multiplier = 1;
    }

    const fare = baseFare * multiplier;

    // Display the fare
    document.getElementById("fare-display").textContent = Estimated Fare: $${fare.toFixed(2)};
});