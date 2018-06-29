var reflexprContainer = document.getElementById('reflexprVis');

var reflexprData = {
    nodes: reflexprNodes,
    edges: reflexprEdges
};

var reflexprNetwork = new vis.Network(
	reflexprContainer,
	reflexprData,
	reflexprOptions
);

