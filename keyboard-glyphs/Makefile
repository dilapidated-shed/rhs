.DEFAULT_GOAL := all
ICK ?= ick
ICK_FLAGS ?=
ICK_LINK_FLAGS ?= -fno-link-libatomic
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -O2

.PHONY: all check clean FORCE

FORCE:

all: glyph_bytes

glyph_bytes: glyph_bytes.c FORCE
	$(ICK) $(ICK_FLAGS) $(CFLAGS) $(ICK_LINK_FLAGS) -o $@ $<

glyph_bytes.actual.txt: glyph_bytes
	./glyph_bytes > $@

check: glyph_bytes.actual.txt glyph_bytes.expected.txt
	cmp glyph_bytes.expected.txt glyph_bytes.actual.txt

clean:
	rm -f glyph_bytes glyph_bytes.actual.txt
