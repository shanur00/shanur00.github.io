# shanur00.github.io

📱 App Screen
│
├─── MaterialApp
│    │
│    └─── ParentWidget (StatefulWidget)
│         │
│         └─── _ParentWidgetState
│              │ userName = "John"
│              │
│              └─── build() creates:
│                   │
│                   ├─── Scaffold
│                   │    │
│                   │    └─── Column
│                   │         │
│                   │         ├─── ChildWidget(name: "John")  ◄━━━━━ 🎯 WIDGET #1 CREATED
│                   │         │    │                                  (Memory Address: 0x001)
│                   │         │    │
│                   │         │    └─── _ChildWidgetState  ◄━━━━━━━ 🎯 STATE OBJECT CREATED
│                   │         │         │                              (Memory Address: 0xAAA)
│                   │         │         │ widget → points to ChildWidget(name: "John")
│                   │         │         │
│                   │         │         ├─── initState() ✅ RUNS
│                   │         │         │    print("initState")
│                   │         │         │
│                   │         │         └─── build() ✅ RUNS
│                   │         │              returns: Text("Hello, John!")
│                   │         │
│                   │         └─── ElevatedButton("Change Name")
│
└─── Screen Shows: "Hello, John!" ✨


┌────────────────────────────────────────────────┐
│  Widget Object (0x001)                         │
│  ┌───────────────────────────────────────┐     │
│  │ ChildWidget                           │     │
│  │ name: "John"                          │     │
│  └───────────────────────────────────────┘     │
└────────────────────────────────────────────────┘
              ▲
              │ widget property points here
              │
┌────────────────────────────────────────────────┐
│  State Object (0xAAA) - STAYS IN MEMORY        │
│  ┌───────────────────────────────────────┐     │
│  │ _ChildWidgetState                     │     │
│  │ widget → ChildWidget(name: "John")    │     │
│  └───────────────────────────────────────┘     │
└────────────────────────────────────────────────┘



╔════════════════════════════════╗
║                                ║
║     Hello, John!               ║
║                                ║
║   ┌──────────────────┐         ║
║   │  Change Name     │ ◄━━━━━  👆 User clicks here!
║   └──────────────────┘         ║
║                                ║
╔════════════════════════════════╗


🔄 setState() called in ParentWidget
│
├─── Parent marks itself as "dirty" (needs rebuild)
│
└─── Flutter scheduler triggers rebuild
     │
     └─── _ParentWidgetState.build() runs again


📱 App Screen (REBUILDING...)
│
├─── MaterialApp
│    │
│    └─── ParentWidget (StatefulWidget)
│         │
│         └─── _ParentWidgetState
│              │ userName = "Alice"  ◄━━━━━ 🔄 VALUE CHANGED!
│              │
│              └─── build() creates NEW widgets:
│                   │
│                   ├─── Scaffold (recreated)
│                   │    │
│                   │    └─── Column (recreated)
│                   │         │
│                   │         ├─── ChildWidget(name: "Alice")  ◄━━━ 🆕 WIDGET #2 CREATED
│                   │         │    │                                  (NEW Memory Address: 0x002)
│                   │         │    │
│                   │         │    │ Flutter compares:
│                   │         │    │ ❓ Same type? ✅ Yes (ChildWidget)
│                   │         │    │ ❓ Same position? ✅ Yes (first child of Column)
│                   │         │    │ ❓ Same key? ✅ Yes (no key = null)
│                   │         │    │
│                   │         │    └─── _ChildWidgetState  ◄━━━━━━━ ♻️ REUSED (NOT recreated!)
│                   │         │         │                              (SAME Memory: 0xAAA)
│                   │         │         │
│                   │         │         │ widget → NOW points to ChildWidget(name: "Alice")
│                   │         │         │
│                   │         │         ├─── initState() ❌ NOT CALLED
│                   │         │         │
│                   │         │         ├─── didUpdateWidget(oldWidget) ✅ CALLED!
│                   │         │         │    │
│                   │         │         │    └─ oldWidget = ChildWidget(name: "John")
│                   │         │         │       widget = ChildWidget(name: "Alice")
│                   │         │         │
│                   │         │         └─── build() ✅ RUNS AGAIN
│                   │         │              returns: Text("Hello, Alice!")
│                   │         │
│                   │         └─── ElevatedButton("Change Name")
│
└─── Screen Shows: "Hello, Alice!" ✨


┌────────────────────────────────────────────────┐
│  OLD Widget Object (0x001) - ABOUT TO BE GC'd  │
│  ┌───────────────────────────────────────┐     │
│  │ ChildWidget                           │     │
│  │ name: "John"  ◄━━━━━━━━━━━━━━━━━━━━━  oldWidget parameter
│  └───────────────────────────────────────┘     │
└────────────────────────────────────────────────┘
              ▲
              │ OLD reference
              │
┌────────────────────────────────────────────────┐
│  State Object (0xAAA) - STAYS IN MEMORY ✅     │
│  ┌───────────────────────────────────────┐     │
│  │ _ChildWidgetState                     │     │
│  │ widget → ChildWidget(name: "John")    │     │
│  └───────────────────────────────────────┘     │
└────────────────────────────────────────────────┘


┌────────────────────────────────────────────────┐
│  NEW Widget Object (0x002) - NOW ACTIVE        │
│  ┌───────────────────────────────────────┐     │
│  │ ChildWidget                           │     │
│  │ name: "Alice"                         │     │
│  └───────────────────────────────────────┘     │
└────────────────────────────────────────────────┘
              ▲
              │ widget property NOW points here
              │
┌────────────────────────────────────────────────┐
│  State Object (0xAAA) - SAME OBJECT! ♻️        │
│  ┌───────────────────────────────────────┐     │
│  │ _ChildWidgetState                     │     │
│  │ widget → ChildWidget(name: "Alice")   │     │
│  └───────────────────────────────────────┘     │
└────────────────────────────────────────────────┘


╔════════════════════════════════════╦════════════════════════════════════╗
║         PHASE 1: FIRST BUILD       ║      PHASE 2: AFTER BUTTON PRESS   ║
╠════════════════════════════════════╬════════════════════════════════════╣
║                                    ║                                    ║
║  ParentWidget                      ║  ParentWidget                      ║
║    userName = "John"               ║    userName = "Alice" ◄━━━ CHANGED ║
║         │                          ║         │                          ║
║         ▼                          ║         ▼                          ║
║  ┌─────────────────────┐           ║  ┌─────────────────────┐           ║
║  │ ChildWidget         │ 0x001     ║  │ ChildWidget         │ 0x002     ║
║  │ name: "John"        │ 🆕 NEW    ║  │ name: "Alice"       │ 🆕 NEW    ║
║  └─────────────────────┘           ║  └─────────────────────┘           ║
║         │                          ║         │                          ║
║         ▼                          ║         ▼                          ║
║  ┌─────────────────────┐           ║  ┌─────────────────────┐           ║
║  │ _ChildWidgetState   │ 0xAAA     ║  │ _ChildWidgetState   │ 0xAAA     ║
║  │ widget → 0x001      │ 🆕 NEW    ║  │ widget → 0x002      │ ♻️ REUSED ║
║  └─────────────────────┘           ║  └─────────────────────┘           ║
║         │                          ║         │                          ║
║         ▼                          ║         ▼                          ║
║  Methods Called:                   ║  Methods Called:                   ║
║  ✅ initState()                    ║  ❌ initState()                    ║
║  ❌ didUpdateWidget()              ║  ✅ didUpdateWidget(0x001)         ║
║  ✅ build()                        ║  ✅ build()                        ║
║         │                          ║         │                          ║
║         ▼                          ║         ▼                          ║
║  Screen:                           ║  Screen:                           ║
║  "Hello, John!"                    ║  "Hello, Alice!"                   ║
║                                    ║                                    ║
╚════════════════════════════════════╩════════════════════════════════════╝
