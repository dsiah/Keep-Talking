var word_code = Math.floor(Math.random() * 8);

// Send to Arduino -- serial
$('.sendit').click(function() {
	var pin_num = 1000000; 
	involtSendString(pin_num, word_code);
	$(this).pinDefine("P10").sendValue();
});
