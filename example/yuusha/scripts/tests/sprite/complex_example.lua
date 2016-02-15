local test = {}

local sprite = require "seal.sprite"
local action = require "seal.action"

local ball = class("ball", sprite)

function ball:ctor(vx, vy, ...)
	ball.__super.ctor(self, sprite.SPRITE_TYPE_IMAGE, ...)

	self.vx, self.vy = vx, vy
end

function ball:update(dt)
	local dx, dy = self.vx * dt / 1000, self.vy * dt / 1000
	local x, y = self.x + dx, self.y + dy
	if x > WINDOW_WIDTH - 16 or x < 0 then
		self.vx = -self.vx
		x = x - dx
	end

	if y > WINDOW_HEIGHT - 16 or y < 0 then
		self.vy = -self.vy
		y = y - dy
	end
	self:set_pos( math.floor(x+0.5), math.floor(y+0.5))

end

function ball:get_speed()
	return self.vx, self.vy
end

function test.sprite()
	sprite.new_sheet("res/atlas_example.png", "atlas_example")

	local root = sprite.new_container{ width = WINDOW_WIDTH, height = WINDOW_HEIGHT }
			math.randomseed(os.time())

	local total_ball = 500
	for i = 1, total_ball do
		local b = ball.new(math.random(-100, 100), math.random(-100, 100), {x = WINDOW_WIDTH/2, y = WINDOW_HEIGHT/2, frame_name = "smile.png"})
		-- local b = ball.new(5, 3, {x = 30, y = 30, frame_name = "smile.png"})
		root:add_child(b)
	end

	-- -- -- sprites move from center to four corners, stop a while, then back to center.
	-- -- for i, v in ipairs(sprites) do
	-- -- 	local spr = sprite.new_image {frame_name = v.start_x, v.start_y} 
	-- -- 	spr:set_pos(v.start_x, v.start_y)

	-- -- 	local move = action.tween(-1, 1000, spr, {x = v.end_x, y = v.end_y, rotation = 360} )
	-- -- 			print('move fin.')	-- 	local call = action.call(function()

	-- -- 		end)

	-- -- 	spr:run_action(action.queue(move, call))∂

	-- -- 	root:add_child(spr)
	-- -- end

	-- add a label in top center
	local name = sprite.new_ttf {
			text = "Complex Example",
			font_path = "res/fonts/Marker Felt.ttf",
			font_size = 24,
			x = WINDOW_WIDTH/2,
			y = WINDOW_HEIGHT,
		}
	name:set_anchor(0.5, 1)
	root:add_child(name)	

	return root
end


return test