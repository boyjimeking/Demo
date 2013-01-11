require "tools"

-- 移动
function Move( actor, targetPos )
	local action = 
	{
		m_targetPos = targetPos,
		m_actor = actor,
		m_usedPos = {}
	}
	-- action:Tick
	function action:Tick(dt)
		local direction = ccpNormalize(ccpSub(self.m_targetPos, self.m_actor:GetPosition()));
		if direction:equals(CCPointMake(0, 0)) then
			return true
		end
		local changed = ccpMult(direction, dt * self.m_actor:GetSpeed());
		local newPos = ccpAdd(self.m_actor:GetPosition(), changed);

		if WorldManager:Instance():GetSceneInfo():IsPointCanStanc(newPos) == false then
			changed.x = dt * self.m_actor:GetSpeed();
			changed.x = changed.x * ((direction.x > 0 and 1) or -1);
			changed.y = 0.0;
			newPos = ccpAdd(self.m_actor:GetPosition(), changed);
			if WorldManager:Instance():GetSceneInfo():IsPointCanStanc(newPos) == false then
				changed.y = dt * self.m_actor:GetSpeed();
				changed.y = changed.y * ((direction.y > 0 and 1) or -1);
				changed.x = 0.0;
				newPos = ccpAdd(self.m_actor:GetPosition(), changed);
				if WorldManager:Instance():GetSceneInfo():IsPointCanStanc(newPos) == false then
					return true
				end
			end
		end

		local isLocked = false
		table.foreach(self.m_usedPos, function( index, value )
			if isLocked then
				return
			end
			if value:equals(newPos) then
				isLocked = true
			end
		end)
		if isLocked then
			cclog("Locked")
			return true
		end

		table.insert(self.m_usedPos, newPos)
		if ccpDistanceSQ(self.m_targetPos, newPos) <= ccpLengthSQ(changed) then
			self.m_actor:SetPosition(self.m_targetPos)
			cclog("arrival")
			return true
		else
			self.m_actor:SetPosition(newPos)
			return false
		end
	end
	if nil ~= actor.tickID then
		CCDirector:sharedDirector():getScheduler():unscheduleScriptEntry(actor.tickID)
	end
	-- Tick
	local function Tick(dt)
		if action:Tick(dt) then
			CCDirector:sharedDirector():getScheduler():unscheduleScriptEntry(actor.tickID)
			actor.tickID = nil
		end
	end
	actor.tickID = CCDirector:sharedDirector():getScheduler():scheduleScriptFunc(Tick, 0, false)
end
