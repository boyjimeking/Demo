require "tools"

UITargetState = {}

function UITargetState.Load()
	UITargetState.slider = CCControlSlider:create("LifeBack.png", "LifeFront.png", "Empty.png")
	local slider = UITargetState.slider
	slider:setTouchEnabled(false)
	slider:setScaleX(5.0)
	local size = CCDirector:sharedDirector():getVisibleSize()
	slider:setPosition(CCPointMake(size.width / 2.0, size.height - 30.0))
	slider:setVisible(false)
	return slider
end