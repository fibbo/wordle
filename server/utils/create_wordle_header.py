from pathlib import Path


def create_wordle_header(source_location: Path):
    files = ["word_bank.txt", "valid_words.txt"]

    target_file = source_location / "src" / "wordle_database.hpp"
    with open(target_file, "w") as t_file:
        t_file.write("#include <array>\n")
        for file in files:
            with open(source_location / file, "r") as f:
                words = f.readlines()
                t_file.write(
                    f"const std::array<const char*, {len(words)}> {file[:-4]} = {{\n"
                )
                for word in words:
                    t_file.write(f'    "{word.strip()}",\n')
                t_file.write("};\n\n")


def run_clang_format(source_location: Path):
    import subprocess

    subprocess.run(
        ["clang-format", "-i", Path(source_location / "src" / "wordle_database.hpp")]
    )


def main(source_location: Path):
    create_wordle_header(source_location)
    run_clang_format(source_location)


if __name__ == "__main__":
    file_path = Path(__file__).resolve()
    print(f"Running {file_path}")
    source_location = file_path.parent.parent.resolve()
    print(f"Running {source_location}")
    main(source_location)
