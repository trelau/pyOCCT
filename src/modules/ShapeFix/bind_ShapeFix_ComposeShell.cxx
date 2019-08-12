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
#include <ShapeFix_Root.hxx>
#include <Standard_Handle.hxx>
#include <ShapeExtend_CompositeSurface.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <ShapeExtend_Status.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <ShapeFix_SequenceOfWireSegment.hxx>
#include <ShapeAnalysis_TransferParameters.hxx>
#include <ShapeFix_ComposeShell.hxx>
#include <Standard_Type.hxx>
#include <ShapeExtend_WireData.hxx>
#include <gp_Lin2d.hxx>
#include <ShapeFix_WireSegment.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Geom_Surface.hxx>
#include <TopAbs_Orientation.hxx>

void bind_ShapeFix_ComposeShell(py::module &mod){

py::class_<ShapeFix_ComposeShell, opencascade::handle<ShapeFix_ComposeShell>, ShapeFix_Root> cls_ShapeFix_ComposeShell(mod, "ShapeFix_ComposeShell", "This class is intended to create a shell from the composite surface (grid of surfaces) and set of wires. It may be either division of the supporting surface of the face, or creating a shape corresponding to face on composite surface which is missing in CAS.CADE but exists in some other systems.");

// Constructors
cls_ShapeFix_ComposeShell.def(py::init<>());

// Fields

// Methods
cls_ShapeFix_ComposeShell.def("Init", (void (ShapeFix_ComposeShell::*)(const opencascade::handle<ShapeExtend_CompositeSurface> &, const TopLoc_Location &, const TopoDS_Face &, const Standard_Real)) &ShapeFix_ComposeShell::Init, "Initializes with composite surface, face and precision. Here face defines both set of wires and way of getting pcurves. Precision is used (together with tolerance of edges) for handling subtle cases, such as tangential intersections.", py::arg("Grid"), py::arg("L"), py::arg("Face"), py::arg("Prec"));
cls_ShapeFix_ComposeShell.def("ClosedMode", (Standard_Boolean & (ShapeFix_ComposeShell::*)()) &ShapeFix_ComposeShell::ClosedMode, "Returns (modifiable) flag for special 'closed' mode which forces ComposeShell to consider all pcurves on closed surface as modulo period. This can reduce reliability, but allows to deal with wires closed in 3d but open in 2d (missing seam) Default is False");
cls_ShapeFix_ComposeShell.def("Perform", (Standard_Boolean (ShapeFix_ComposeShell::*)()) &ShapeFix_ComposeShell::Perform, "Performs the work on already loaded data.");
cls_ShapeFix_ComposeShell.def("SplitEdges", (void (ShapeFix_ComposeShell::*)()) &ShapeFix_ComposeShell::SplitEdges, "Splits edges in the original shape by grid. This is a part of Perform() which does not produce any resulting shape; the only result is filled context where splittings are recorded.");
cls_ShapeFix_ComposeShell.def("Result", (const TopoDS_Shape & (ShapeFix_ComposeShell::*)() const) &ShapeFix_ComposeShell::Result, "Returns resulting shell or face (or Null shape if not done)");
cls_ShapeFix_ComposeShell.def("Status", (Standard_Boolean (ShapeFix_ComposeShell::*)(const ShapeExtend_Status) const) &ShapeFix_ComposeShell::Status, "Queries status of last call to Perform() OK : nothing done (some kind of error) DONE1: splitting is done, at least one new face created DONE2: splitting is done, several new faces obtained FAIL1: misoriented wire encountered (handled) FAIL2: recoverable parity error FAIL3: edge with no pcurve on supporting face FAIL4: unrecoverable algorithm error (parity check)", py::arg("status"));
cls_ShapeFix_ComposeShell.def("DispatchWires", (void (ShapeFix_ComposeShell::*)(TopTools_SequenceOfShape &, ShapeFix_SequenceOfWireSegment &) const) &ShapeFix_ComposeShell::DispatchWires, "Creates new faces from the set of (closed) wires. Each wire is put on corresponding patch in the composite surface, and all pcurves on the initial (pseudo)face are reassigned to that surface. If several wires are one inside another, single face is created.", py::arg("faces"), py::arg("wires"));
cls_ShapeFix_ComposeShell.def("SetTransferParamTool", (void (ShapeFix_ComposeShell::*)(const opencascade::handle<ShapeAnalysis_TransferParameters> &)) &ShapeFix_ComposeShell::SetTransferParamTool, "Sets tool for transfer parameters from 3d to 2d and vice versa.", py::arg("TransferParam"));
cls_ShapeFix_ComposeShell.def("GetTransferParamTool", (opencascade::handle<ShapeAnalysis_TransferParameters> (ShapeFix_ComposeShell::*)() const) &ShapeFix_ComposeShell::GetTransferParamTool, "Gets tool for transfer parameters from 3d to 2d and vice versa.");
cls_ShapeFix_ComposeShell.def_static("get_type_name_", (const char * (*)()) &ShapeFix_ComposeShell::get_type_name, "None");
cls_ShapeFix_ComposeShell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_ComposeShell::get_type_descriptor, "None");
cls_ShapeFix_ComposeShell.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_ComposeShell::*)() const) &ShapeFix_ComposeShell::DynamicType, "None");

// Enums

}