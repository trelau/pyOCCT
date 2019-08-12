/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <MAT_ListOfBisector.hxx>
#include <MAT_Arc.hxx>
#include <MAT_BasicElt.hxx>
#include <MAT_Node.hxx>
#include <MAT_DataMapOfIntegerBasicElt.hxx>
#include <MAT_Graph.hxx>
#include <Standard_Type.hxx>
#include <MAT_DataMapOfIntegerArc.hxx>
#include <MAT_DataMapOfIntegerNode.hxx>

void bind_MAT_Graph(py::module &mod){

py::class_<MAT_Graph, opencascade::handle<MAT_Graph>, Standard_Transient> cls_MAT_Graph(mod, "MAT_Graph", "The Class Graph permits the exploration of the Bisector Locus.");

// Constructors
cls_MAT_Graph.def(py::init<>());

// Fields

// Methods
cls_MAT_Graph.def("Perform", (void (MAT_Graph::*)(const Standard_Boolean, const opencascade::handle<MAT_ListOfBisector> &, const Standard_Integer, const Standard_Integer)) &MAT_Graph::Perform, "Construct <me> from the result of the method <CreateMat> of the class <MAT> from <MAT>.", py::arg("SemiInfinite"), py::arg("TheRoots"), py::arg("NbBasicElts"), py::arg("NbArcs"));
cls_MAT_Graph.def("Arc", (opencascade::handle<MAT_Arc> (MAT_Graph::*)(const Standard_Integer) const) &MAT_Graph::Arc, "Return the Arc of index <Index> in <theArcs>.", py::arg("Index"));
cls_MAT_Graph.def("BasicElt", (opencascade::handle<MAT_BasicElt> (MAT_Graph::*)(const Standard_Integer) const) &MAT_Graph::BasicElt, "Return the BasicElt of index <Index> in <theBasicElts>.", py::arg("Index"));
cls_MAT_Graph.def("Node", (opencascade::handle<MAT_Node> (MAT_Graph::*)(const Standard_Integer) const) &MAT_Graph::Node, "Return the Node of index <Index> in <theNodes>.", py::arg("Index"));
cls_MAT_Graph.def("NumberOfArcs", (Standard_Integer (MAT_Graph::*)() const) &MAT_Graph::NumberOfArcs, "Return the number of arcs of <me>.");
cls_MAT_Graph.def("NumberOfNodes", (Standard_Integer (MAT_Graph::*)() const) &MAT_Graph::NumberOfNodes, "Return the number of nodes of <me>.");
cls_MAT_Graph.def("NumberOfBasicElts", (Standard_Integer (MAT_Graph::*)() const) &MAT_Graph::NumberOfBasicElts, "Return the number of basic elements of <me>.");
cls_MAT_Graph.def("NumberOfInfiniteNodes", (Standard_Integer (MAT_Graph::*)() const) &MAT_Graph::NumberOfInfiniteNodes, "Return the number of infinites nodes of <me>.");
cls_MAT_Graph.def("FusionOfBasicElts", [](MAT_Graph &self, const Standard_Integer IndexElt1, const Standard_Integer IndexElt2, Standard_Boolean & MergeArc1, Standard_Integer & GeomIndexArc1, Standard_Integer & GeomIndexArc2, Standard_Boolean & MergeArc2, Standard_Integer & GeomIndexArc3, Standard_Integer & GeomIndexArc4){ self.FusionOfBasicElts(IndexElt1, IndexElt2, MergeArc1, GeomIndexArc1, GeomIndexArc2, MergeArc2, GeomIndexArc3, GeomIndexArc4); return std::tuple<Standard_Boolean &, Standard_Integer &, Standard_Integer &, Standard_Boolean &, Standard_Integer &, Standard_Integer &>(MergeArc1, GeomIndexArc1, GeomIndexArc2, MergeArc2, GeomIndexArc3, GeomIndexArc4); }, "Merge two BasicElts. The End of the BasicElt Elt1 of IndexElt1 becomes The End of the BasicElt Elt2 of IndexElt2. Elt2 is replaced in the arcs by Elt1, Elt2 is eliminated.", py::arg("IndexElt1"), py::arg("IndexElt2"), py::arg("MergeArc1"), py::arg("GeomIndexArc1"), py::arg("GeomIndexArc2"), py::arg("MergeArc2"), py::arg("GeomIndexArc3"), py::arg("GeomIndexArc4"));
cls_MAT_Graph.def("CompactArcs", (void (MAT_Graph::*)()) &MAT_Graph::CompactArcs, "None");
cls_MAT_Graph.def("CompactNodes", (void (MAT_Graph::*)()) &MAT_Graph::CompactNodes, "None");
cls_MAT_Graph.def("ChangeBasicElts", (void (MAT_Graph::*)(const MAT_DataMapOfIntegerBasicElt &)) &MAT_Graph::ChangeBasicElts, "None", py::arg("NewMap"));
cls_MAT_Graph.def("ChangeBasicElt", (opencascade::handle<MAT_BasicElt> (MAT_Graph::*)(const Standard_Integer)) &MAT_Graph::ChangeBasicElt, "None", py::arg("Index"));
cls_MAT_Graph.def_static("get_type_name_", (const char * (*)()) &MAT_Graph::get_type_name, "None");
cls_MAT_Graph.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_Graph::get_type_descriptor, "None");
cls_MAT_Graph.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_Graph::*)() const) &MAT_Graph::DynamicType, "None");

// Enums

}