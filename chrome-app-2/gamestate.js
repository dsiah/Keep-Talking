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
	this.style.display = 'none';
	setScreen();
	startTimer();
}

function startTimer() {
	gmodel.timer = new Date();
	setInterval(changeTime, 1000);
}

function changeTime() {
	var delta = Math.round((new Date() - gmodel.timer) / 1000);
	document.getElementById('watch').innerText = delta;	
}

// Game State
var gmodel  = { 
	screen: 1, 
	timer: null, 
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

wipe();