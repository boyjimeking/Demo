require "tools"

-- 移动
function Move( actor, targetPos )
	local co
	co = coroutine.create(
		function()
			local function OnMoveOver()
				coroutine.resume(co)
			end
			actor:MoveTo(targetPos, OnMoveOver)
			coroutine.yield()
		end
	)
	coroutine.resume(co)
end
