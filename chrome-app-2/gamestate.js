function wipe() {
	var screens = document.getElementsByClassName('screen');
	for (var i = 0; i < screens.length; i++) {
		screens[i].style.display = 'none';
	}
}

function setScreen() {
	gmodel.screen = this.id || gmodel.screen;
	wipe();
	var omm = document.getElementById('Game-' + gmodel.screen);
	omm.style.display = '';
}

function begin() {
	$('#stopbtn').css('display', '');
	this.style.display = 'none';
	setScreen();
	startTimer();
}

function startTimer() {
	gmodel.timer = new Date();
	gmodel.clock = setInterval(changeTime, 1000);
}

function stopTimer() {
	clearInterval(gmodel.clock);
}

function changeTime() {
	var delta = Math.round((new Date() - gmodel.timer) / 1000);
	if (gmodel.toppy - delta < 0) {
		clearInterval(gmodel.clock)
		$('body').css('background', '-webkit-gradient(linear, left top, left bottom, from(#fff), to(#f00)) fixed');
		$('#Timer').innerHTML('GAME OVER, you blew it!');
		return
	}
	document.getElementById('watch').innerText = gmodel.toppy - delta;

}

// Game State
var gmodel  = { 
	screen: 1, 
	timer: null, 
	toppy: 300,
	game1win: null, 
	game2win: null, 
	game3win: null 
}

// Components
var btns    = document.getElementsByClassName('sbtn');
var screens = document.getElementsByClassName('screen');

// Load listeners
document.getElementById('Start-Game').addEventListener('click', begin);
for (var i = 0; i < btns.length; i++) {
	btns[i].addEventListener('click', setScreen);
}

$('#stopbtn').on('click', stopTimer);

wipe();