def create_header(prefix):
    temp_path = f"{prefix}_template.h"
    structure_path = f"{prefix}_structure.h"
    temp = [line.rstrip() for line in open(temp_path, "r")]
    strc = [line.rstrip() for line in open(structure_path, "r")]
    tag = strc[0].split("TAG=")[1]
    save_path = f"{prefix}_{tag}.h"
    temp = "\n".join(temp)
    strc = "\n".join(strc)
    open(save_path, "w").write((strc+temp).replace("TAG",tag))

# compile.pyとcompprog.hの編集を同時に行う

create_header("./lib/data_structures/segment_tree/segment_tree")