faces = {
        "Tetrahedron" : 4,
        "Cube" : 6,
        "Octahedron" : 8,
        "Dodecahedron" : 12,
        "Icosahedron" : 20
        }

if __name__ == "__main__":
    n = int(raw_input())
    face_count = 0
    for i in xrange(n):
        face_count += faces[raw_input()]
    print face_count
