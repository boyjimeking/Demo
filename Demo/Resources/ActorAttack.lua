require "tools"

-- 攻击目标
function Attack( actor, target )
	local co
	local function OnMoveOver()
		coroutine.resume(co)
	end
	co = coroutine.create(
		function()
			actor:MoveTo(target:GetPosition(), OnMoveOver)
			coroutine.yield()
			actor:StartAttack(target)
		end
	)
	coroutine.resume(co)
end