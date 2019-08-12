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
#include <BRepClass3d_BndBoxTree.hxx>
#include <NCollection_UBTree.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <Bnd_Box.hxx>
#include <gp_Lin.hxx>
#include <Geom_Line.hxx>
#include <Precision.hxx>
#include <NCollection_Sequence.hxx>
#include <GeomAdaptor_Curve.hxx>

void bind_BRepClass3d_BndBoxTreeSelectorLine(py::module &mod){

py::class_<BRepClass3d_BndBoxTreeSelectorLine, std::unique_ptr<BRepClass3d_BndBoxTreeSelectorLine, Deleter<BRepClass3d_BndBoxTreeSelectorLine>>, BRepClass3d_BndBoxTree::Selector> cls_BRepClass3d_BndBoxTreeSelectorLine(mod, "BRepClass3d_BndBoxTreeSelectorLine", "None");

// Constructors
// cls_BRepClass3d_BndBoxTreeSelectorLine.def(py::init<const TopTools_IndexedMapOfShape &>(), py::arg("theMapOfShape"));

// Fields

// Methods
cls_BRepClass3d_BndBoxTreeSelectorLine.def("Reject", (Standard_Boolean (BRepClass3d_BndBoxTreeSelectorLine::*)(const Bnd_Box &) const) &BRepClass3d_BndBoxTreeSelectorLine::Reject, "None", py::arg("theBox"));
cls_BRepClass3d_BndBoxTreeSelectorLine.def("Accept", (Standard_Boolean (BRepClass3d_BndBoxTreeSelectorLine::*)(const Standard_Integer &)) &BRepClass3d_BndBoxTreeSelectorLine::Accept, "None", py::arg("theObj"));
cls_BRepClass3d_BndBoxTreeSelectorLine.def("SetCurrentLine", (void (BRepClass3d_BndBoxTreeSelectorLine::*)(const gp_Lin &, const Standard_Real)) &BRepClass3d_BndBoxTreeSelectorLine::SetCurrentLine, "None", py::arg("theL"), py::arg("theMaxParam"));
cls_BRepClass3d_BndBoxTreeSelectorLine.def("GetEdgeParam", [](BRepClass3d_BndBoxTreeSelectorLine &self, const Standard_Integer i, TopoDS_Edge & theOutE, Standard_Real & theOutParam, Standard_Real & outLParam){ self.GetEdgeParam(i, theOutE, theOutParam, outLParam); return std::tuple<Standard_Real &, Standard_Real &>(theOutParam, outLParam); }, "None", py::arg("i"), py::arg("theOutE"), py::arg("theOutParam"), py::arg("outLParam"));
cls_BRepClass3d_BndBoxTreeSelectorLine.def("GetVertParam", [](BRepClass3d_BndBoxTreeSelectorLine &self, const Standard_Integer i, TopoDS_Vertex & theOutV, Standard_Real & outLParam){ self.GetVertParam(i, theOutV, outLParam); return outLParam; }, "None", py::arg("i"), py::arg("theOutV"), py::arg("outLParam"));
cls_BRepClass3d_BndBoxTreeSelectorLine.def("GetNbEdgeParam", (Standard_Integer (BRepClass3d_BndBoxTreeSelectorLine::*)() const) &BRepClass3d_BndBoxTreeSelectorLine::GetNbEdgeParam, "None");
cls_BRepClass3d_BndBoxTreeSelectorLine.def("GetNbVertParam", (Standard_Integer (BRepClass3d_BndBoxTreeSelectorLine::*)() const) &BRepClass3d_BndBoxTreeSelectorLine::GetNbVertParam, "None");
cls_BRepClass3d_BndBoxTreeSelectorLine.def("ClearResults", (void (BRepClass3d_BndBoxTreeSelectorLine::*)()) &BRepClass3d_BndBoxTreeSelectorLine::ClearResults, "None");

// Enums

}