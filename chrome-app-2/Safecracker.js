gmodel.game2loop = setInterval(loop, 500);

function loop() {
	if (gmodel.screen != 2)
		return
	// Serial reads
	var safe_state = {
		'A': Number($('.A17').attr('value')),
		'B': Number($('.A18').attr('value')),
		'C': Number($('.A19').attr('value')),
		'SAFES OPEN': Number($('.A20').attr('value'))
	}

	// console.log(safe_state);

	$('#safe-dis1').text(safe_state['A']);
	$('#safe-dis2').text(safe_state['B']);
	$('#safe-dis3').text(safe_state['C']);
	$('#safe-progress').text(safe_state['SAFES OPEN']);

	if (safe_state['SAFES OPEN'] == 3) {
		clearInterval(gmodel.game2loop);
		$('.game-2-info').addClass('winsplash')
		gmodel.game2win = true;
	}
		
}


