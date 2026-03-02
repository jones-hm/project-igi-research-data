# 🎮 IGI Camera Engine – Quick Overview

This is a **high-level overview** of how the camera works in Project I.G.I and in game engines generally — short, clear, and practical.

---

# 🧠 1️⃣ What Is a Camera in a Game Engine?

A camera in a 3D engine is:

> A mathematical transform that defines how the world is viewed.

It consists of:

- 📍 **Position** (X, Y, Z)
- 🔄 **Rotation** (orientation in space)
- 📐 **Projection settings** (FOV, near/far plane)

The camera does not move the world.

Instead:

```
World is transformed relative to camera.
```

---

# 🎥 2️⃣ Basic Camera Concepts

## 📍 Position

Defines where the camera exists in 3D space:

```
X → Left / Right
Y → Forward / Backward
Z → Up / Down
```

---

## 🔄 Rotation

Defined by three angles:

### 🧭 Yaw
- Turn left / right
- Rotation around vertical axis

### 🔼 Pitch
- Look up / down
- Rotation around side axis

### 🔁 Roll
- Tilt sideways
- Rarely used in FPS games

In IGI:

- Yaw + Pitch are active
- Roll is typically unused

---

# 🧮 3️⃣ Rotation Matrix (Why 9 Floats?)

Instead of storing yaw/pitch directly,
IGI converts them into a **3×3 rotation matrix**.

Conceptually:

```c
float rotation[9]; // 3x3 orientation matrix
```

Why?

- Faster rendering math
- Stable 3D transformations
- Direct use in view matrix calculations

---

# 🏗 4️⃣ Structure of IGI Camera (Simplified)

Internally it looks similar to:

```c
typedef struct IGICamera
{
    float rotation[9];   // Orientation
    float position[3];   // X, Y, Z
    float stateData[...];
} IGICamera;
```

Then copied into a viewport structure used by the renderer.

---

# 🖥 5️⃣ What Is the Viewport?

The viewport is:

> The final camera buffer used by the renderer.

It contains:

- Rotation (floats)
- Position (often doubles for precision)
- Rendering-related values

Renderer reads this every frame.

---

# 🔁 6️⃣ IGI Camera Flow (Simplified)

Each frame:

```
Mouse Input
     ↓
Update Yaw & Pitch
     ↓
Build Rotation Matrix
     ↓
Update Position
     ↓
Copy Camera → Viewport
     ↓
Render Scene
```

---

# 🎬 7️⃣ Use Cases of IGI Camera System

IGI uses the same base system for:

- 🎯 First-person gameplay
- 👤 Third-person mode
- 🎥 Mission scripted cameras
- 🎬 Cutscenes
- 🛰 Debug camera modes

The difference is only how:

- Position is updated
- Rotation is controlled
- Camera state flags are set

---

# 🧩 Core Takeaway

IGI Camera =

- Position in 3D space
- Orientation (Yaw + Pitch → Rotation Matrix)
- Copied into viewport
- Used by renderer

Everything visual in the game depends on this transform.

That’s the entire foundation of the IGI camera engine. 🚀
