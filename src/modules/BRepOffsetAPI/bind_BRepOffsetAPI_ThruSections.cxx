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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Vertex.hxx>
#include <Approx_ParametrizationType.hxx>
#include <GeomAbs_Shape.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_Handle.hxx>
#include <Geom_BSplineSurface.hxx>
#include <TopTools_Array1OfShape.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfInteger.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>

void bind_BRepOffsetAPI_ThruSections(py::module &mod){

py::class_<BRepOffsetAPI_ThruSections, BRepBuilderAPI_MakeShape> cls_BRepOffsetAPI_ThruSections(mod, "BRepOffsetAPI_ThruSections", "Describes functions to build a loft. This is a shell or a solid passing through a set of sections in a given sequence. Usually sections are wires, but the first and the last sections may be vertices (punctual sections).");

// Constructors
cls_BRepOffsetAPI_ThruSections.def(py::init<>());
cls_BRepOffsetAPI_ThruSections.def(py::init<const Standard_Boolean>(), py::arg("isSolid"));
cls_BRepOffsetAPI_ThruSections.def(py::init<const Standard_Boolean, const Standard_Boolean>(), py::arg("isSolid"), py::arg("ruled"));
cls_BRepOffsetAPI_ThruSections.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Real>(), py::arg("isSolid"), py::arg("ruled"), py::arg("pres3d"));

// Fields

// Methods
// cls_BRepOffsetAPI_ThruSections.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_ThruSections::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_ThruSections.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_ThruSections::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_ThruSections.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_ThruSections::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_ThruSections.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_ThruSections::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_ThruSections.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_ThruSections::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_ThruSections.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_ThruSections::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_ThruSections.def("Init", [](BRepOffsetAPI_ThruSections &self) -> void { return self.Init(); });
cls_BRepOffsetAPI_ThruSections.def("Init", [](BRepOffsetAPI_ThruSections &self, const Standard_Boolean a0) -> void { return self.Init(a0); });
cls_BRepOffsetAPI_ThruSections.def("Init", [](BRepOffsetAPI_ThruSections &self, const Standard_Boolean a0, const Standard_Boolean a1) -> void { return self.Init(a0, a1); });
cls_BRepOffsetAPI_ThruSections.def("Init", (void (BRepOffsetAPI_ThruSections::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Real)) &BRepOffsetAPI_ThruSections::Init, "Initializes this algorithm for building a shell or a solid passing through a set of sections, where: - isSolid is set to true if this construction algorithm is required to build a solid or to false if it is required to build a shell. false is the default value; - ruled is set to true if the faces generated between the edges of two consecutive wires are ruled surfaces or to false (the default value) if they are smoothed out by approximation, - pres3d defines the precision criterion used by the approximation algorithm; the default value is 1.0e-6. Use AddWire and AddVertex to define the successive sections of the shell or solid to be built.", py::arg("isSolid"), py::arg("ruled"), py::arg("pres3d"));
cls_BRepOffsetAPI_ThruSections.def("AddWire", (void (BRepOffsetAPI_ThruSections::*)(const TopoDS_Wire &)) &BRepOffsetAPI_ThruSections::AddWire, "Adds the wire wire to the set of sections through which the shell or solid is built. Use the Build function to construct the shape.", py::arg("wire"));
cls_BRepOffsetAPI_ThruSections.def("AddVertex", (void (BRepOffsetAPI_ThruSections::*)(const TopoDS_Vertex &)) &BRepOffsetAPI_ThruSections::AddVertex, "Adds the vertex Vertex (punctual section) to the set of sections through which the shell or solid is built. A vertex may be added to the set of sections only as first or last section. At least one wire must be added to the set of sections by the method AddWire. Use the Build function to construct the shape.", py::arg("aVertex"));
cls_BRepOffsetAPI_ThruSections.def("CheckCompatibility", [](BRepOffsetAPI_ThruSections &self) -> void { return self.CheckCompatibility(); });
cls_BRepOffsetAPI_ThruSections.def("CheckCompatibility", (void (BRepOffsetAPI_ThruSections::*)(const Standard_Boolean)) &BRepOffsetAPI_ThruSections::CheckCompatibility, "Sets/unsets the option to compute origin and orientation on wires to avoid twisted results and update wires to have same number of edges.", py::arg("check"));
cls_BRepOffsetAPI_ThruSections.def("SetSmoothing", (void (BRepOffsetAPI_ThruSections::*)(const Standard_Boolean)) &BRepOffsetAPI_ThruSections::SetSmoothing, "Define the approximation algorithm", py::arg("UseSmoothing"));
cls_BRepOffsetAPI_ThruSections.def("SetParType", (void (BRepOffsetAPI_ThruSections::*)(const Approx_ParametrizationType)) &BRepOffsetAPI_ThruSections::SetParType, "Define the type of parametrization used in the approximation", py::arg("ParType"));
cls_BRepOffsetAPI_ThruSections.def("SetContinuity", (void (BRepOffsetAPI_ThruSections::*)(const GeomAbs_Shape)) &BRepOffsetAPI_ThruSections::SetContinuity, "Define the Continuity used in the approximation", py::arg("C"));
cls_BRepOffsetAPI_ThruSections.def("SetCriteriumWeight", (void (BRepOffsetAPI_ThruSections::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &BRepOffsetAPI_ThruSections::SetCriteriumWeight, "define the Weights associed to the criterium used in the optimization.", py::arg("W1"), py::arg("W2"), py::arg("W3"));
cls_BRepOffsetAPI_ThruSections.def("SetMaxDegree", (void (BRepOffsetAPI_ThruSections::*)(const Standard_Integer)) &BRepOffsetAPI_ThruSections::SetMaxDegree, "Define the maximal U degree of result surface", py::arg("MaxDeg"));
cls_BRepOffsetAPI_ThruSections.def("ParType", (Approx_ParametrizationType (BRepOffsetAPI_ThruSections::*)() const) &BRepOffsetAPI_ThruSections::ParType, "returns the type of parametrization used in the approximation");
cls_BRepOffsetAPI_ThruSections.def("Continuity", (GeomAbs_Shape (BRepOffsetAPI_ThruSections::*)() const) &BRepOffsetAPI_ThruSections::Continuity, "returns the Continuity used in the approximation");
cls_BRepOffsetAPI_ThruSections.def("MaxDegree", (Standard_Integer (BRepOffsetAPI_ThruSections::*)() const) &BRepOffsetAPI_ThruSections::MaxDegree, "returns the maximal U degree of result surface");
cls_BRepOffsetAPI_ThruSections.def("UseSmoothing", (Standard_Boolean (BRepOffsetAPI_ThruSections::*)() const) &BRepOffsetAPI_ThruSections::UseSmoothing, "Define the approximation algorithm");
cls_BRepOffsetAPI_ThruSections.def("CriteriumWeight", [](BRepOffsetAPI_ThruSections &self, Standard_Real & W1, Standard_Real & W2, Standard_Real & W3){ self.CriteriumWeight(W1, W2, W3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(W1, W2, W3); }, "returns the Weights associed to the criterium used in the optimization.", py::arg("W1"), py::arg("W2"), py::arg("W3"));
cls_BRepOffsetAPI_ThruSections.def("Build", (void (BRepOffsetAPI_ThruSections::*)()) &BRepOffsetAPI_ThruSections::Build, "None");
cls_BRepOffsetAPI_ThruSections.def("FirstShape", (const TopoDS_Shape & (BRepOffsetAPI_ThruSections::*)() const) &BRepOffsetAPI_ThruSections::FirstShape, "Returns the TopoDS Shape of the bottom of the loft if solid");
cls_BRepOffsetAPI_ThruSections.def("LastShape", (const TopoDS_Shape & (BRepOffsetAPI_ThruSections::*)() const) &BRepOffsetAPI_ThruSections::LastShape, "Returns the TopoDS Shape of the top of the loft if solid");
cls_BRepOffsetAPI_ThruSections.def("GeneratedFace", (TopoDS_Shape (BRepOffsetAPI_ThruSections::*)(const TopoDS_Shape &) const) &BRepOffsetAPI_ThruSections::GeneratedFace, "if Ruled Returns the Face generated by each edge except the last wire if smoothed Returns the Face generated by each edge of the first wire", py::arg("Edge"));
cls_BRepOffsetAPI_ThruSections.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_ThruSections::*)(const TopoDS_Shape &)) &BRepOffsetAPI_ThruSections::Generated, "Returns a list of new shapes generated from the shape S by the shell-generating algorithm. This function is redefined from BRepBuilderAPI_MakeShape::Generated. S can be an edge or a vertex of a given Profile (see methods AddWire and AddVertex).", py::arg("S"));
cls_BRepOffsetAPI_ThruSections.def("Wires", (const TopTools_ListOfShape & (BRepOffsetAPI_ThruSections::*)() const) &BRepOffsetAPI_ThruSections::Wires, "Returns the list of original wires");

// Enums

}