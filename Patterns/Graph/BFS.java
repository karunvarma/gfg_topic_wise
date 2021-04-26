public void bfs(Node root) {
    ArrayDeque<Node> queue = new ArrayDeque<>();
    queue.add(root);
    Set<Node> visited = new HashSet<>();
    while (queue.size() > 0) {
        Node node = queue.pop();
        for (Node neighbor : getNeighbors(node)) {
            if (visited.contains(neighbor)) {
                continue;
            }
            queue.add(neighbor);
            visited.add(neighbor);
        }
    }
}
