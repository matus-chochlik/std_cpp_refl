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

reflexprNetwork.on(
	"selectNode",
	function (params) {
		options = {
			animation: true
		}
		reflexprNetwork.focus(params.nodes[0], options);
	}
);
