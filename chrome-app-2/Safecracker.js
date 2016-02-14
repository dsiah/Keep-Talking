gmodel.game2loop = setInterval(loop, 500);

function loop() {
	if (gmodel.screen != 2)
		return
	// Serial reads
	var safe_state = {
		'A': Number($('.A13').attr('value')),
		'B': Number($('.A14').attr('value')),
		'C': Number($('.A15').attr('value')),
		'SAFES OPEN': Number($('.A16').attr('value'))
	}

	$('#safe-dis1').text(safe_state['A']);
	$('#safe-dis2').text(safe_state['B']);
	$('#safe-dis3').text(safe_state['C']);
	$('#safe-progress').text(safe_state['SAFES OPEN']);

	if (safe_state['SAFES OPEN'] >= 3) {
		clearInterval(gmodel.game2loop);
		gmodel.game2win = true;
	}
		
}


