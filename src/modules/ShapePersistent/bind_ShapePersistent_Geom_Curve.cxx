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
#include <ShapePersistent_Geom.hxx>
#include <StdObjMgt_SharedObject.hxx>
#include <ShapePersistent_Geom_Curve.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <ShapePersistent_HArray1.hxx>
#include <StdLPersistent_HArray1.hxx>
#include <gp_Dir.hxx>
#include <Geom_Line.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <Geom_Circle.hxx>
#include <gp_Circ.hxx>
#include <Geom_Ellipse.hxx>
#include <gp_Elips.hxx>
#include <Geom_Hyperbola.hxx>
#include <gp_Hypr.hxx>
#include <Geom_Parabola.hxx>
#include <gp_Parab.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom_OffsetCurve.hxx>

void bind_ShapePersistent_Geom_Curve(py::module &mod){

/*
py::class_<ShapePersistent_Geom_Curve> cls_ShapePersistent_Geom_Curve(mod, "ShapePersistent_Geom_Curve", "None");

// Constructors

// Fields

// Methods
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_Line> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a line", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_Circle> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a circle", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_Ellipse> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a ellipse", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_Hyperbola> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a hyperbola", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_Parabola> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a parabola", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_BezierCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a Bezier curve", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_BSplineCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a BSpline curve", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_TrimmedCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a trimmed curve", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_OffsetCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for an offset curve", py::arg("theCurve"), py::arg("theMap"));

// Enums
*/

}