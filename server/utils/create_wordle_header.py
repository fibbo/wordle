from pathlib import Path


def main(source_location: Path):
    files = ["word_bank.txt", "valid_words.txt"]

    for file in files:
        with open(source_location / file, "r") as f:
            words = f.readlines()

        with open("../src/wordle.hpp", "a") as f:
            f.write("#include <array>\n")
            f.write(f"const std::array<const char*, {len(words)}> {file[:-4]} = {{\n")
            for word in words:
                f.write(f'    "{word.strip()}",\n')
            f.write("};\n\n")


if __name__ == "__main__":
    file_path = Path(__file__)
    source_location = file_path.parent.parent
    print(f"Running {source_location}...")
    main(source_location)
