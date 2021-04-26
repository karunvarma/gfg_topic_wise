import java.util.*;

public void dfs(Node root, Set<Node> visited) {

    if (visited.contains(root)) {
        continue;
    }

    for (Node child : node.children) {
        dfs(child);
    }
}
