
# Save as hello_maya_ui.py in directory that will be sourced by Maya.
# Execute the following code in a python tab of Maya's script editor.
"""
import hello_maya_ui as mui
reload(mui)
dialog = mui.DemoDialog()
"""
from PySide2.QtGui import *
from PySide2.QtWidgets import *
from PySide2.QtCore import *
from PySide2.QtUiTools import *
	
import maya.cmds as cmds
  
class DemoDialog(QDialog):
	# "__init__" is a special function that is automatically called 
	# by python when an instance of our DemoDialog class is created. 
	def __init__(self, parent=None):
		# Because our class is derived from QDialog its constructor is called.
		QDialog.__init__(self, parent)
		
		# Ensure our window stays in front and give it a title
		self.setWindowFlags(Qt.WindowStaysOnTopHint)
		self.setWindowTitle("DemoDialog")
		self.setFixedSize(400, 200)
		
		# Create and assign the main (vertical) layout.
		vlayout = QVBoxLayout()
		self.setLayout(vlayout)    
		
		# Ensure the buttonPanel is pushed down to the lower edge of the
		# Dialog window.
		vlayout.addStretch()    
		
		self.addButtonPanel(vlayout)
		self.show()
  
	def addButtonPanel(self, parentLayout):
		# Add a Button and connect it to our custom buttonAction() method.
		self.button = QPushButton("OK")
		self.button.clicked.connect(self.buttonAction)
		
		# For easthetics we add the button to a horizonal layout and use
		# stretch() to ensure it is pushed to the right hand edge.
		hlayout = QHBoxLayout()
		hlayout.addStretch()
		hlayout.addWidget(self.button)
		parentLayout.addLayout(hlayout)
	#--------------------------------------------------------------------
	def buttonAction(self):
		print("button has been clicked")
	#--------------------------------------------------------------------
