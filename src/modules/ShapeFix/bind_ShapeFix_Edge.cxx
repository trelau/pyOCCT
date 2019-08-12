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
#include <TColStd_HArray1OfReal.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <ShapeConstruct_ProjectCurveOnSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <ShapeAnalysis_Surface.hxx>
#include <ShapeExtend_Status.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <ShapeFix_Edge.hxx>
#include <Standard_Type.hxx>

void bind_ShapeFix_Edge(py::module &mod){

py::class_<ShapeFix_Edge, opencascade::handle<ShapeFix_Edge>, Standard_Transient> cls_ShapeFix_Edge(mod, "ShapeFix_Edge", "Fixing invalid edge. Geometrical and/or topological inconsistency: - no 3d curve or pcurve, - mismatching orientation of 3d curve and pcurve, - incorrect SameParameter flag (curve deviation is greater than edge tolerance), - not adjacent curves (3d or pcurve) to the vertices.");

// Constructors
cls_ShapeFix_Edge.def(py::init<>());

// Fields

// Methods
cls_ShapeFix_Edge.def("Projector", (opencascade::handle<ShapeConstruct_ProjectCurveOnSurface> (ShapeFix_Edge::*)()) &ShapeFix_Edge::Projector, "Returns the projector used for recomputing missing pcurves Can be used for adjusting parameters of projector");
cls_ShapeFix_Edge.def("FixRemovePCurve", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &)) &ShapeFix_Edge::FixRemovePCurve, "None", py::arg("edge"), py::arg("face"));
cls_ShapeFix_Edge.def("FixRemovePCurve", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &)) &ShapeFix_Edge::FixRemovePCurve, "Removes the pcurve(s) of the edge if it does not match the vertices Check is done Use : It is to be called when pcurve of an edge can be wrong (e.g., after import from IGES) Returns: True, if does not match, removed (status DONE) False, (status OK) if matches or (status FAIL) if no pcurve, nothing done", py::arg("edge"), py::arg("surface"), py::arg("location"));
cls_ShapeFix_Edge.def("FixRemoveCurve3d", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &)) &ShapeFix_Edge::FixRemoveCurve3d, "Removes 3d curve of the edge if it does not match the vertices Returns: True, if does not match, removed (status DONE) False, (status OK) if matches or (status FAIL) if no 3d curve, nothing done", py::arg("edge"));
cls_ShapeFix_Edge.def("FixAddPCurve", [](ShapeFix_Edge &self, const TopoDS_Edge & a0, const TopoDS_Face & a1, const Standard_Boolean a2) -> Standard_Boolean { return self.FixAddPCurve(a0, a1, a2); });
cls_ShapeFix_Edge.def("FixAddPCurve", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Boolean, const Standard_Real)) &ShapeFix_Edge::FixAddPCurve, "See method below for information", py::arg("edge"), py::arg("face"), py::arg("isSeam"), py::arg("prec"));
cls_ShapeFix_Edge.def("FixAddPCurve", [](ShapeFix_Edge &self, const TopoDS_Edge & a0, const opencascade::handle<Geom_Surface> & a1, const TopLoc_Location & a2, const Standard_Boolean a3) -> Standard_Boolean { return self.FixAddPCurve(a0, a1, a2, a3); });
cls_ShapeFix_Edge.def("FixAddPCurve", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Boolean, const Standard_Real)) &ShapeFix_Edge::FixAddPCurve, "See method below for information", py::arg("edge"), py::arg("surface"), py::arg("location"), py::arg("isSeam"), py::arg("prec"));
cls_ShapeFix_Edge.def("FixAddPCurve", [](ShapeFix_Edge &self, const TopoDS_Edge & a0, const TopoDS_Face & a1, const Standard_Boolean a2, const opencascade::handle<ShapeAnalysis_Surface> & a3) -> Standard_Boolean { return self.FixAddPCurve(a0, a1, a2, a3); });
cls_ShapeFix_Edge.def("FixAddPCurve", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Boolean, const opencascade::handle<ShapeAnalysis_Surface> &, const Standard_Real)) &ShapeFix_Edge::FixAddPCurve, "See method below for information", py::arg("edge"), py::arg("face"), py::arg("isSeam"), py::arg("surfana"), py::arg("prec"));
cls_ShapeFix_Edge.def("FixAddPCurve", [](ShapeFix_Edge &self, const TopoDS_Edge & a0, const opencascade::handle<Geom_Surface> & a1, const TopLoc_Location & a2, const Standard_Boolean a3, const opencascade::handle<ShapeAnalysis_Surface> & a4) -> Standard_Boolean { return self.FixAddPCurve(a0, a1, a2, a3, a4); });
cls_ShapeFix_Edge.def("FixAddPCurve", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Boolean, const opencascade::handle<ShapeAnalysis_Surface> &, const Standard_Real)) &ShapeFix_Edge::FixAddPCurve, "Adds pcurve(s) of the edge if missing (by projecting 3d curve) Parameter isSeam indicates if the edge is a seam. The parameter <prec> defines the precision for calculations. If it is 0 (default), the tolerance of the edge is taken. Remark : This method is rather for internal use since it accepts parameter <surfana> for optimization of computations Use : It is to be called after FixRemovePCurve (if removed) or in any case when edge can have no pcurve Returns: True if pcurve was added, else False Status : OK : Pcurve exists FAIL1: No 3d curve FAIL2: fail during projecting DONE1: Pcurve was added DONE2: specific case of pcurve going through degenerated point on sphere encountered during projection (see class ShapeConstruct_ProjectCurveOnSurface for more info)", py::arg("edge"), py::arg("surface"), py::arg("location"), py::arg("isSeam"), py::arg("surfana"), py::arg("prec"));
cls_ShapeFix_Edge.def("FixAddCurve3d", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &)) &ShapeFix_Edge::FixAddCurve3d, "Tries to build 3d curve of the edge if missing Use : It is to be called after FixRemoveCurve3d (if removed) or in any case when edge can have no 3d curve Returns: True if 3d curve was added, else False Status : OK : 3d curve exists FAIL1: BRepLib::BuildCurve3d() has failed DONE1: 3d curve was added", py::arg("edge"));
cls_ShapeFix_Edge.def("FixVertexTolerance", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &)) &ShapeFix_Edge::FixVertexTolerance, "None", py::arg("edge"), py::arg("face"));
cls_ShapeFix_Edge.def("FixVertexTolerance", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &)) &ShapeFix_Edge::FixVertexTolerance, "Increases the tolerances of the edge vertices to comprise the ends of 3d curve and pcurve on the given face (first method) or all pcurves stored in an edge (second one) Returns: True, if tolerances have been increased, otherwise False Status: OK : the original tolerances have not been changed DONE1: the tolerance of first vertex has been increased DONE2: the tolerance of last vertex has been increased", py::arg("edge"));
cls_ShapeFix_Edge.def("FixReversed2d", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &)) &ShapeFix_Edge::FixReversed2d, "None", py::arg("edge"), py::arg("face"));
cls_ShapeFix_Edge.def("FixReversed2d", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &)) &ShapeFix_Edge::FixReversed2d, "Fixes edge if pcurve is directed opposite to 3d curve Check is done by call to the function ShapeAnalysis_Edge::CheckCurve3dWithPCurve() Warning: For seam edge this method will check and fix the pcurve in only one direction. Hence, it should be called twice for seam edge: once with edge orientation FORWARD and once with REVERSED. Returns: False if nothing done, True if reversed (status DONE) Status: OK - pcurve OK, nothing done FAIL1 - no pcurve FAIL2 - no 3d curve DONE1 - pcurve was reversed", py::arg("edge"), py::arg("surface"), py::arg("location"));
cls_ShapeFix_Edge.def("FixSameParameter", [](ShapeFix_Edge &self, const TopoDS_Edge & a0) -> Standard_Boolean { return self.FixSameParameter(a0); });
cls_ShapeFix_Edge.def("FixSameParameter", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const Standard_Real)) &ShapeFix_Edge::FixSameParameter, "Tries to make edge SameParameter and sets corresponding tolerance and SameParameter flag. First, it makes edge same range if SameRange flag is not set.", py::arg("edge"), py::arg("tolerance"));
cls_ShapeFix_Edge.def("FixSameParameter", [](ShapeFix_Edge &self, const TopoDS_Edge & a0, const TopoDS_Face & a1) -> Standard_Boolean { return self.FixSameParameter(a0, a1); });
cls_ShapeFix_Edge.def("FixSameParameter", (Standard_Boolean (ShapeFix_Edge::*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real)) &ShapeFix_Edge::FixSameParameter, "Tries to make edge SameParameter and sets corresponding tolerance and SameParameter flag. First, it makes edge same range if SameRange flag is not set.", py::arg("edge"), py::arg("face"), py::arg("tolerance"));
cls_ShapeFix_Edge.def("Status", (Standard_Boolean (ShapeFix_Edge::*)(const ShapeExtend_Status) const) &ShapeFix_Edge::Status, "Returns the status (in the form of True/False) of last Fix", py::arg("status"));
cls_ShapeFix_Edge.def("SetContext", (void (ShapeFix_Edge::*)(const opencascade::handle<ShapeBuild_ReShape> &)) &ShapeFix_Edge::SetContext, "Sets context", py::arg("context"));
cls_ShapeFix_Edge.def("Context", (opencascade::handle<ShapeBuild_ReShape> (ShapeFix_Edge::*)() const) &ShapeFix_Edge::Context, "Returns context");
cls_ShapeFix_Edge.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Edge::get_type_name, "None");
cls_ShapeFix_Edge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Edge::get_type_descriptor, "None");
cls_ShapeFix_Edge.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Edge::*)() const) &ShapeFix_Edge::DynamicType, "None");

// Enums

}