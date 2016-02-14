var bar_one, bar_two, bar_three;


function loop() {
	// console.log($('.A0').attr('value'));
	// console.log($('.A1').attr('value'));
	// console.log($('.A2').attr('value'));
	// console.log($('.A3').attr('value'));
	// console.log($('.A4').attr('value'));
	// console.log($('.A5').attr('value'));

	// Serial reads
	console.log('Safes open: ' + $('.A16').attr('value'));
}

setInterval(loop, 1000);