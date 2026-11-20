"""Regenerates PROBLEMS.md. Run from anywhere: python3 tools/gen_index.py"""
import os, re, sys
from urllib.parse import quote

ROOT = sys.argv[1] if len(sys.argv) > 1 else os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "PROBLEMS.md")
SKIP = {"debug.cpp", "debug_template.cpp", "x.cpp", "_.cpp", "tempCodeRunnerFile.cpp"}
SECTIONS = ["Phase 0", "Phase 1", "Phase 2", "Phase 3", "Phase 4", "Phase 5",
            "VVIMP-Questions", "CSES", "Codeforces Ladder"]


def natkey(s):
    return [int(t) if t.isdigit() else t.lower() for t in re.split(r"(\d+)", s)]


def pretty(fname):
    name = fname[:-4]
    name = re.sub(r"^\d+_", "", name)            # VVIMP numbering
    m = re.match(r"^([A-G])_(.+)$", name)        # Codeforces index prefix
    tag = ""
    if m:
        tag, name = m.group(1), m.group(2)
    name = name.replace("_", " ").strip()
    if name.isdigit():
        name = f"Pattern {name}"
    return f"{name} ({tag})" if tag else name


lines = ["# Problem Index", "",
         "Every solution in the repo, grouped by phase and topic. Click a name to open the code.", "",
         "Codeforces problems show their index letter in brackets, e.g. *Kefa and Park (C)*. "
         "In VVIMP-Questions, problems without a link haven't been solved yet.", ""]

lines.append("**Jump to:** " + " · ".join(
    f"[{s}](#{s.lower().replace(' ', '-')})" for s in SECTIONS))
lines.append("")

total = 0
for sec in SECTIONS:
    secpath = os.path.join(ROOT, sec)
    groups = []
    for dirpath, dirnames, filenames in os.walk(secpath):
        dirnames[:] = sorted([d for d in dirnames if not d.startswith(".") and d != "output"], key=natkey)
        files = sorted([f for f in filenames if f.endswith(".cpp") and f not in SKIP], key=natkey)
        if not files:
            continue
        rel = os.path.relpath(dirpath, secpath)
        groups.append((rel, dirpath, files))
    groups.sort(key=lambda g: natkey(g[0]) if g[0] != "." else [""])

    lines += [f"## {sec}", ""]
    for rel, dirpath, files in groups:
        title = "General" if rel == "." else rel.replace(os.sep, " / ")
        items = []
        for f in files:
            full = os.path.join(dirpath, f)
            empty = os.path.getsize(full) == 0
            label = pretty(f)
            if empty and sec != "VVIMP-Questions":
                continue
            if empty:
                items.append(label)
            else:
                url = quote(os.path.relpath(full, ROOT).replace(os.sep, "/"), safe="/")
                items.append(f"[{label}]({url})")
                total += 1
        if not items:
            continue
        lines += [f"**{title}**  ", " · ".join(items), ""]

open(OUT, "w").write("\n".join(lines).rstrip() + "\n")
print("linked solutions:", total)
