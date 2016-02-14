import pyglet
import serial

ser = serial.Serial('/dev/cu.usbmodem1421', 9600) # Establish the connection on a specific port
c1, c2 = 0, 0 									  # Below 32 everything in ASCII is gibberish

class TextObj(object):
	def __init__(self, initial_text):
		self.txt = ser.readline()

	def update(dt):
		cont = ser.readline()
		if (len(cont) > 0):
			self.txt = ser.readline()

text = TextObj(ser.readline())
window = pyglet.window.Window()
label = pyglet.text.Label(text.txt,
          font_name='Times New Roman',
          font_size=36,
          x=window.width // 2, y=window.height // 2,
          anchor_x='center', anchor_y='center')

@window.event
def on_key_press(symbol, modifiers):
    print 'A key was pressed'

# def update(dt):
# 	text = ser.readline()


@window.event
def on_draw():
	print(text.txt)

	# if ('1: ON' in text):
	# 	c1 += 1
	# 	print('1: ON', c1)

	# if ('2: ON' in text):
	# 	c2 += 1
	# 	print('2: ON', c2)
	
	window.clear()
	label.draw()


# pyglet.clock.schedule_interval(update, 1 / 120.0)
pyglet.app.run()