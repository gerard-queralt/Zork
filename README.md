# Zork

## About

This project is a tribute of the game [Zork](https://en.wikipedia.org/wiki/Zork_I).

Zork is a 1980 text adventure game developed by four members of the MIT Dynamic Modeling Group —
Tim Anderson, Marc Blank, Bruce Daniels, and Dave Lebling.

In the game, the player is controlled through text commands.
Their objective is to collect all the loot found in the dungeon.

## Author

At the time of making this project, I am about to finish my degree in Informatics Engineering
at the Facultat d'Informàtica de Barcelona. I wish to enter the video game industry
and help make some amazing games, just like the ones that made me love this art
and pursue this path.

## How to play

The player interacts with the world using commands. These are the commands you can use:

### Look

You can look around the room you are in by typing:

```bash
> look
```

This action is performed automatically when entering a room.

### Move/Go

To move to an adjacent room, you can type:

```bash
> move <direction>
```

or

```bash
> go <direction>
```

Where `<direction>` can be `north`, `south`, `east`, `west`, `up` or `down`,
or their first letter - `n`, `s`, etc.

You can also move simply with

```bash
> <direction>
```

Some rooms will be locked, but if you have their keys they will open automatically
when you try to go through them.

### Get/Take

You can pick up most items in the game by typing:

```bash
> get <item>
```

or

```bash
> take <item>
```

Where `<item>` is the name of an item in the room, which are always one word.
Unfortunately they are pretty strict, but the names can be inferred from the
description given, so I hope it won't be a problem.

### Inventory

If you want to check your inventory you can do so by writing:

```bash
> inventory
```

or

```bash
> i
```

### Drop

To drop an item in your inventory and leave it on the room you can write:

```bash
> drop <item>
```

Where `<item>` is the name of an item in your inventory.

### Open

Some items (actually, just one) are locked inside other items.
To access them, you must first open their container with the command:

```bash
> open <item>
```

Where `<item>` is an item in the room that can be opened.
As I said, in this small version there is only one such item,
but it is really easy to add more.

### Put in

After you have opened the container you can put other items in it by typing:

```bash
> put <item> in <container>
```

Where `<item>` is an item in you inventory and `<container>` is an item in the room
that can store items in it and is open
(just like the one explained in the Open command).

### Equip

If you have an item in your inventory that you want to use as a weapon you can type:

```bash
> equip <item>
```

Where `<item>` is the name of an item in your inventory.

### Unequip

If you wish to unequip your weapon you can do so writing

```bash
> unequip
```

You don't have to unequip your current weapon to equip another one.
Dropping the item you are using as a weapon also causes you to unequip it.

### Attack

When you find an enemy you can attack it typing:

```bash
> attack <enemy>
```

Where `<enemy>` is the name of an enemy in the room. As is the case with items,
names are only one word and are exposed as best as possible in the description
of the NPC. The exception is the boss of the game, which, as stated in-game,
is called "boss", so no need to try to infer it.

If you forgot to equip a weapon before combat, you may want to avoid losing
a turn with the extended version of this command:

```bash
> attack <enemy> with <item>
```

Which will automatically equip the item as your weapon as long as you have it
in you inventory.

## How to finish the game

The objective of the game is to enter the house's cellar and slay the giant
troll lurking in it. This monster is slow, but can easily kill you if you give
it enough time. It's also very tough; normal weapons barely scratch it.
There might be hope, though: inside the house is a mysterious door that could
have a way to kill the monster hidden behind it. Unfortunately, it has no keyhole;
instead it has a circular shape carved on it, as if something was ment to be inserted.
Seems you will have to keep exploring...

If you want a step-by-step walkthrough on how to beat the game, you can find it
in the file [HowToBeat](HowToBeat.txt).

## Link

This project is hosted in [this GitHub repository](https://github.com/gerard-queralt/Zork).

## License

[MIT License](https://choosealicense.com/licenses/mit/)