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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <gce_ErrorType.hxx>
#include <GC_Root.hxx>
#include <gp_Circ.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Standard_Handle.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <GC_MakeArcOfCircle.hxx>
#include <gp_Elips.hxx>
#include <GC_MakeArcOfEllipse.hxx>
#include <gp_Hypr.hxx>
#include <GC_MakeArcOfHyperbola.hxx>
#include <gp_Parab.hxx>
#include <GC_MakeArcOfParabola.hxx>
#include <gp_Ax2.hxx>
#include <gp_Dir.hxx>
#include <gp_Ax1.hxx>
#include <Geom_Circle.hxx>
#include <GC_MakeCircle.hxx>
#include <gp_Cone.hxx>
#include <Geom_ConicalSurface.hxx>
#include <GC_MakeConicalSurface.hxx>
#include <gp_Cylinder.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <GC_MakeCylindricalSurface.hxx>
#include <Geom_Ellipse.hxx>
#include <GC_MakeEllipse.hxx>
#include <Geom_Hyperbola.hxx>
#include <GC_MakeHyperbola.hxx>
#include <gp_Lin.hxx>
#include <Geom_Line.hxx>
#include <GC_MakeLine.hxx>
#include <gp_Pln.hxx>
#include <Geom_Transformation.hxx>
#include <GC_MakeMirror.hxx>
#include <Geom_Plane.hxx>
#include <GC_MakePlane.hxx>
#include <GC_MakeRotation.hxx>
#include <GC_MakeScale.hxx>
#include <GC_MakeSegment.hxx>
#include <GC_MakeTranslation.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>
#include <GC_MakeTrimmedCone.hxx>
#include <GC_MakeTrimmedCylinder.hxx>

PYBIND11_MODULE(GC, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gce");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom");

// CLASS: GC_ROOT
py::class_<GC_Root> cls_GC_Root(mod, "GC_Root", "This class implements the common services for all classes of gce which report error.");

// Constructors
cls_GC_Root.def(py::init<>());

// Methods
// cls_GC_Root.def_static("operator new_", (void * (*)(size_t)) &GC_Root::operator new, "None", py::arg("theSize"));
// cls_GC_Root.def_static("operator delete_", (void (*)(void *)) &GC_Root::operator delete, "None", py::arg("theAddress"));
// cls_GC_Root.def_static("operator new[]_", (void * (*)(size_t)) &GC_Root::operator new[], "None", py::arg("theSize"));
// cls_GC_Root.def_static("operator delete[]_", (void (*)(void *)) &GC_Root::operator delete[], "None", py::arg("theAddress"));
// cls_GC_Root.def_static("operator new_", (void * (*)(size_t, void *)) &GC_Root::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_Root.def_static("operator delete_", (void (*)(void *, void *)) &GC_Root::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_Root.def("IsDone", (Standard_Boolean (GC_Root::*)() const) &GC_Root::IsDone, "Returns true if the construction is successful.");
cls_GC_Root.def("Status", (gce_ErrorType (GC_Root::*)() const) &GC_Root::Status, "Returns the status of the construction: - gce_Done, if the construction is successful, or - another value of the gce_ErrorType enumeration indicating why the construction failed.");

// CLASS: GC_MAKEARCOFCIRCLE
py::class_<GC_MakeArcOfCircle, GC_Root> cls_GC_MakeArcOfCircle(mod, "GC_MakeArcOfCircle", "Implements construction algorithms for an arc of circle in 3D space. The result is a Geom_TrimmedCurve curve. A MakeArcOfCircle object provides a framework for: - defining the construction of the arc of circle, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed arc of circle.");

// Constructors
cls_GC_MakeArcOfCircle.def(py::init<const gp_Circ &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Circ"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Sense"));
cls_GC_MakeArcOfCircle.def(py::init<const gp_Circ &, const gp_Pnt &, const Standard_Real, const Standard_Boolean>(), py::arg("Circ"), py::arg("P"), py::arg("Alpha"), py::arg("Sense"));
cls_GC_MakeArcOfCircle.def(py::init<const gp_Circ &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("Circ"), py::arg("P1"), py::arg("P2"), py::arg("Sense"));
cls_GC_MakeArcOfCircle.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_GC_MakeArcOfCircle.def(py::init<const gp_Pnt &, const gp_Vec &, const gp_Pnt &>(), py::arg("P1"), py::arg("V"), py::arg("P2"));

// Methods
// cls_GC_MakeArcOfCircle.def_static("operator new_", (void * (*)(size_t)) &GC_MakeArcOfCircle::operator new, "None", py::arg("theSize"));
// cls_GC_MakeArcOfCircle.def_static("operator delete_", (void (*)(void *)) &GC_MakeArcOfCircle::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeArcOfCircle.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeArcOfCircle::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeArcOfCircle.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeArcOfCircle::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeArcOfCircle.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeArcOfCircle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeArcOfCircle.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeArcOfCircle::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeArcOfCircle.def("Value", (const opencascade::handle<Geom_TrimmedCurve> & (GC_MakeArcOfCircle::*)() const) &GC_MakeArcOfCircle::Value, "Returns the constructed arc of circle. Exceptions StdFail_NotDone if no arc of circle is constructed.");

// CLASS: GC_MAKEARCOFELLIPSE
py::class_<GC_MakeArcOfEllipse, GC_Root> cls_GC_MakeArcOfEllipse(mod, "GC_MakeArcOfEllipse", "Implements construction algorithms for an arc of ellipse in 3D space. The result is a Geom_TrimmedCurve curve. A MakeArcOfEllipse object provides a framework for: - defining the construction of the arc of ellipse, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed arc of ellipse.");

// Constructors
cls_GC_MakeArcOfEllipse.def(py::init<const gp_Elips &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Elips"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Sense"));
cls_GC_MakeArcOfEllipse.def(py::init<const gp_Elips &, const gp_Pnt &, const Standard_Real, const Standard_Boolean>(), py::arg("Elips"), py::arg("P"), py::arg("Alpha"), py::arg("Sense"));
cls_GC_MakeArcOfEllipse.def(py::init<const gp_Elips &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("Elips"), py::arg("P1"), py::arg("P2"), py::arg("Sense"));

// Methods
// cls_GC_MakeArcOfEllipse.def_static("operator new_", (void * (*)(size_t)) &GC_MakeArcOfEllipse::operator new, "None", py::arg("theSize"));
// cls_GC_MakeArcOfEllipse.def_static("operator delete_", (void (*)(void *)) &GC_MakeArcOfEllipse::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeArcOfEllipse.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeArcOfEllipse::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeArcOfEllipse.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeArcOfEllipse::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeArcOfEllipse.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeArcOfEllipse::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeArcOfEllipse.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeArcOfEllipse::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeArcOfEllipse.def("Value", (const opencascade::handle<Geom_TrimmedCurve> & (GC_MakeArcOfEllipse::*)() const) &GC_MakeArcOfEllipse::Value, "Returns the constructed arc of ellipse.");

// CLASS: GC_MAKEARCOFHYPERBOLA
py::class_<GC_MakeArcOfHyperbola, GC_Root> cls_GC_MakeArcOfHyperbola(mod, "GC_MakeArcOfHyperbola", "Implements construction algorithms for an arc of hyperbola in 3D space. The result is a Geom_TrimmedCurve curve. A MakeArcOfHyperbola object provides a framework for: - defining the construction of the arc of hyperbola, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed arc of hyperbola.");

// Constructors
cls_GC_MakeArcOfHyperbola.def(py::init<const gp_Hypr &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Hypr"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Sense"));
cls_GC_MakeArcOfHyperbola.def(py::init<const gp_Hypr &, const gp_Pnt &, const Standard_Real, const Standard_Boolean>(), py::arg("Hypr"), py::arg("P"), py::arg("Alpha"), py::arg("Sense"));
cls_GC_MakeArcOfHyperbola.def(py::init<const gp_Hypr &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("Hypr"), py::arg("P1"), py::arg("P2"), py::arg("Sense"));

// Methods
// cls_GC_MakeArcOfHyperbola.def_static("operator new_", (void * (*)(size_t)) &GC_MakeArcOfHyperbola::operator new, "None", py::arg("theSize"));
// cls_GC_MakeArcOfHyperbola.def_static("operator delete_", (void (*)(void *)) &GC_MakeArcOfHyperbola::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeArcOfHyperbola.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeArcOfHyperbola::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeArcOfHyperbola.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeArcOfHyperbola::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeArcOfHyperbola.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeArcOfHyperbola::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeArcOfHyperbola.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeArcOfHyperbola::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeArcOfHyperbola.def("Value", (const opencascade::handle<Geom_TrimmedCurve> & (GC_MakeArcOfHyperbola::*)() const) &GC_MakeArcOfHyperbola::Value, "Returns the constructed arc of hyperbola.");

// CLASS: GC_MAKEARCOFPARABOLA
py::class_<GC_MakeArcOfParabola, GC_Root> cls_GC_MakeArcOfParabola(mod, "GC_MakeArcOfParabola", "Implements construction algorithms for an arc of parabola in 3D space. The result is a Geom_TrimmedCurve curve. A MakeArcOfParabola object provides a framework for: - defining the construction of the arc of parabola, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed arc of parabola.");

// Constructors
cls_GC_MakeArcOfParabola.def(py::init<const gp_Parab &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Parab"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Sense"));
cls_GC_MakeArcOfParabola.def(py::init<const gp_Parab &, const gp_Pnt &, const Standard_Real, const Standard_Boolean>(), py::arg("Parab"), py::arg("P"), py::arg("Alpha"), py::arg("Sense"));
cls_GC_MakeArcOfParabola.def(py::init<const gp_Parab &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("Parab"), py::arg("P1"), py::arg("P2"), py::arg("Sense"));

// Methods
// cls_GC_MakeArcOfParabola.def_static("operator new_", (void * (*)(size_t)) &GC_MakeArcOfParabola::operator new, "None", py::arg("theSize"));
// cls_GC_MakeArcOfParabola.def_static("operator delete_", (void (*)(void *)) &GC_MakeArcOfParabola::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeArcOfParabola.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeArcOfParabola::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeArcOfParabola.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeArcOfParabola::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeArcOfParabola.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeArcOfParabola::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeArcOfParabola.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeArcOfParabola::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeArcOfParabola.def("Value", (const opencascade::handle<Geom_TrimmedCurve> & (GC_MakeArcOfParabola::*)() const) &GC_MakeArcOfParabola::Value, "Returns the constructed arc of parabola.");

// CLASS: GC_MAKECIRCLE
py::class_<GC_MakeCircle, GC_Root> cls_GC_MakeCircle(mod, "GC_MakeCircle", "This class implements the following algorithms used to create Cirlec from Geom.");

// Constructors
cls_GC_MakeCircle.def(py::init<const gp_Circ &>(), py::arg("C"));
cls_GC_MakeCircle.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Radius"));
cls_GC_MakeCircle.def(py::init<const gp_Circ &, const Standard_Real>(), py::arg("Circ"), py::arg("Dist"));
cls_GC_MakeCircle.def(py::init<const gp_Circ &, const gp_Pnt &>(), py::arg("Circ"), py::arg("Point"));
cls_GC_MakeCircle.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_GC_MakeCircle.def(py::init<const gp_Pnt &, const gp_Dir &, const Standard_Real>(), py::arg("Center"), py::arg("Norm"), py::arg("Radius"));
cls_GC_MakeCircle.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real>(), py::arg("Center"), py::arg("PtAxis"), py::arg("Radius"));
cls_GC_MakeCircle.def(py::init<const gp_Ax1 &, const Standard_Real>(), py::arg("Axis"), py::arg("Radius"));

// Methods
// cls_GC_MakeCircle.def_static("operator new_", (void * (*)(size_t)) &GC_MakeCircle::operator new, "None", py::arg("theSize"));
// cls_GC_MakeCircle.def_static("operator delete_", (void (*)(void *)) &GC_MakeCircle::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeCircle.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeCircle::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeCircle.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeCircle::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeCircle.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeCircle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeCircle.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeCircle::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeCircle.def("Value", (const opencascade::handle<Geom_Circle> & (GC_MakeCircle::*)() const) &GC_MakeCircle::Value, "Returns the constructed circle. Exceptions StdFail_NotDone if no circle is constructed.");

// CLASS: GC_MAKECONICALSURFACE
py::class_<GC_MakeConicalSurface, GC_Root> cls_GC_MakeConicalSurface(mod, "GC_MakeConicalSurface", "This class implements the following algorithms used to create a ConicalSurface from Geom. * Create a ConicalSurface parallel to another and passing through a point. * Create a ConicalSurface parallel to another at a distance <Dist>. * Create a ConicalSurface by 4 points. * Create a ConicalSurface by its axis and 2 points. * Create a ConicalSurface by 2 points and 2 radius. The local coordinate system of the ConicalSurface is defined with an axis placement (see class ElementarySurface).");

// Constructors
cls_GC_MakeConicalSurface.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("Ang"), py::arg("Radius"));
cls_GC_MakeConicalSurface.def(py::init<const gp_Cone &>(), py::arg("C"));
cls_GC_MakeConicalSurface.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_GC_MakeConicalSurface.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("R1"), py::arg("R2"));

// Methods
// cls_GC_MakeConicalSurface.def_static("operator new_", (void * (*)(size_t)) &GC_MakeConicalSurface::operator new, "None", py::arg("theSize"));
// cls_GC_MakeConicalSurface.def_static("operator delete_", (void (*)(void *)) &GC_MakeConicalSurface::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeConicalSurface.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeConicalSurface::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeConicalSurface.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeConicalSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeConicalSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeConicalSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeConicalSurface.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeConicalSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeConicalSurface.def("Value", (const opencascade::handle<Geom_ConicalSurface> & (GC_MakeConicalSurface::*)() const) &GC_MakeConicalSurface::Value, "Returns the constructed cone. Exceptions StdFail_NotDone if no cone is constructed.");

// CLASS: GC_MAKECYLINDRICALSURFACE
py::class_<GC_MakeCylindricalSurface, GC_Root> cls_GC_MakeCylindricalSurface(mod, "GC_MakeCylindricalSurface", "This class implements the following algorithms used to create a CylindricalSurface from Geom. * Create a CylindricalSurface parallel to another and passing through a point. * Create a CylindricalSurface parallel to another at a distance <Dist>. * Create a CylindricalSurface passing through 3 points. * Create a CylindricalSurface by its axis and radius. * Create a cylindricalSurface by its circular base. The local coordinate system of the CylindricalSurface is defined with an axis placement (see class ElementarySurface).");

// Constructors
cls_GC_MakeCylindricalSurface.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Radius"));
cls_GC_MakeCylindricalSurface.def(py::init<const gp_Cylinder &>(), py::arg("C"));
cls_GC_MakeCylindricalSurface.def(py::init<const gp_Cylinder &, const gp_Pnt &>(), py::arg("Cyl"), py::arg("Point"));
cls_GC_MakeCylindricalSurface.def(py::init<const gp_Cylinder &, const Standard_Real>(), py::arg("Cyl"), py::arg("Dist"));
cls_GC_MakeCylindricalSurface.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_GC_MakeCylindricalSurface.def(py::init<const gp_Ax1 &, const Standard_Real>(), py::arg("Axis"), py::arg("Radius"));
cls_GC_MakeCylindricalSurface.def(py::init<const gp_Circ &>(), py::arg("Circ"));

// Methods
// cls_GC_MakeCylindricalSurface.def_static("operator new_", (void * (*)(size_t)) &GC_MakeCylindricalSurface::operator new, "None", py::arg("theSize"));
// cls_GC_MakeCylindricalSurface.def_static("operator delete_", (void (*)(void *)) &GC_MakeCylindricalSurface::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeCylindricalSurface.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeCylindricalSurface::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeCylindricalSurface.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeCylindricalSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeCylindricalSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeCylindricalSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeCylindricalSurface.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeCylindricalSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeCylindricalSurface.def("Value", (const opencascade::handle<Geom_CylindricalSurface> & (GC_MakeCylindricalSurface::*)() const) &GC_MakeCylindricalSurface::Value, "Returns the constructed cylinder. Exceptions StdFail_NotDone if no cylinder is constructed.");

// CLASS: GC_MAKEELLIPSE
py::class_<GC_MakeEllipse, GC_Root> cls_GC_MakeEllipse(mod, "GC_MakeEllipse", "This class implements construction algorithms for an ellipse in 3D space. The result is a Geom_Ellipse ellipse. A MakeEllipse object provides a framework for: - defining the construction of the ellipse, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed ellipse.");

// Constructors
cls_GC_MakeEllipse.def(py::init<const gp_Elips &>(), py::arg("E"));
cls_GC_MakeEllipse.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_GC_MakeEllipse.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("S1"), py::arg("S2"), py::arg("Center"));

// Methods
// cls_GC_MakeEllipse.def_static("operator new_", (void * (*)(size_t)) &GC_MakeEllipse::operator new, "None", py::arg("theSize"));
// cls_GC_MakeEllipse.def_static("operator delete_", (void (*)(void *)) &GC_MakeEllipse::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeEllipse.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeEllipse::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeEllipse.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeEllipse::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeEllipse.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeEllipse::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeEllipse.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeEllipse::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeEllipse.def("Value", (const opencascade::handle<Geom_Ellipse> & (GC_MakeEllipse::*)() const) &GC_MakeEllipse::Value, "Returns the constructed ellipse. Exceptions StdFail_NotDone if no ellipse is constructed.");

// CLASS: GC_MAKEHYPERBOLA
py::class_<GC_MakeHyperbola, GC_Root> cls_GC_MakeHyperbola(mod, "GC_MakeHyperbola", "This class implements construction algorithms for a hyperbola in 3D space. The result is a Geom_Hyperbola hyperbola. A MakeHyperbola object provides a framework for: - defining the construction of the hyperbola, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed hyperbola. To define the main branch of an hyperbola. The parameterization range is ]-infinite,+infinite[ It is possible to get the other branch and the two conjugate branches of the main branch.");

// Constructors
cls_GC_MakeHyperbola.def(py::init<const gp_Hypr &>(), py::arg("H"));
cls_GC_MakeHyperbola.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_GC_MakeHyperbola.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("S1"), py::arg("S2"), py::arg("Center"));

// Methods
// cls_GC_MakeHyperbola.def_static("operator new_", (void * (*)(size_t)) &GC_MakeHyperbola::operator new, "None", py::arg("theSize"));
// cls_GC_MakeHyperbola.def_static("operator delete_", (void (*)(void *)) &GC_MakeHyperbola::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeHyperbola.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeHyperbola::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeHyperbola.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeHyperbola::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeHyperbola.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeHyperbola::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeHyperbola.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeHyperbola::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeHyperbola.def("Value", (const opencascade::handle<Geom_Hyperbola> & (GC_MakeHyperbola::*)() const) &GC_MakeHyperbola::Value, "Returns the constructed hyperbola. Exceptions StdFail_NotDone if no hyperbola is constructed.");

// CLASS: GC_MAKELINE
py::class_<GC_MakeLine, GC_Root> cls_GC_MakeLine(mod, "GC_MakeLine", "This class implements the following algorithms used to create a Line from Geom. * Create a Line parallel to another and passing through a point. * Create a Line passing through 2 points. A MakeLine object provides a framework for: - defining the construction of the line, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed line.");

// Constructors
cls_GC_MakeLine.def(py::init<const gp_Ax1 &>(), py::arg("A1"));
cls_GC_MakeLine.def(py::init<const gp_Lin &>(), py::arg("L"));
cls_GC_MakeLine.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));
cls_GC_MakeLine.def(py::init<const gp_Lin &, const gp_Pnt &>(), py::arg("Lin"), py::arg("Point"));
cls_GC_MakeLine.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));

// Methods
// cls_GC_MakeLine.def_static("operator new_", (void * (*)(size_t)) &GC_MakeLine::operator new, "None", py::arg("theSize"));
// cls_GC_MakeLine.def_static("operator delete_", (void (*)(void *)) &GC_MakeLine::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeLine.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeLine::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeLine.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeLine::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeLine.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeLine.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeLine::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeLine.def("Value", (const opencascade::handle<Geom_Line> & (GC_MakeLine::*)() const) &GC_MakeLine::Value, "Returns the constructed line. Exceptions StdFail_NotDone if no line is constructed.");

// CLASS: GC_MAKEMIRROR
py::class_<GC_MakeMirror> cls_GC_MakeMirror(mod, "GC_MakeMirror", "This class implements elementary construction algorithms for a symmetrical transformation in 3D space about a point, axis or plane. The result is a Geom_Transformation transformation. A MakeMirror object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_GC_MakeMirror.def(py::init<const gp_Pnt &>(), py::arg("Point"));
cls_GC_MakeMirror.def(py::init<const gp_Ax1 &>(), py::arg("Axis"));
cls_GC_MakeMirror.def(py::init<const gp_Lin &>(), py::arg("Line"));
cls_GC_MakeMirror.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("Point"), py::arg("Direc"));
cls_GC_MakeMirror.def(py::init<const gp_Pln &>(), py::arg("Plane"));
cls_GC_MakeMirror.def(py::init<const gp_Ax2 &>(), py::arg("Plane"));

// Methods
// cls_GC_MakeMirror.def_static("operator new_", (void * (*)(size_t)) &GC_MakeMirror::operator new, "None", py::arg("theSize"));
// cls_GC_MakeMirror.def_static("operator delete_", (void (*)(void *)) &GC_MakeMirror::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeMirror.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeMirror::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeMirror.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeMirror::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeMirror.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeMirror::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeMirror.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeMirror::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeMirror.def("Value", (const opencascade::handle<Geom_Transformation> & (GC_MakeMirror::*)() const) &GC_MakeMirror::Value, "Returns the constructed transformation.");

// CLASS: GC_MAKEPLANE
py::class_<GC_MakePlane, GC_Root> cls_GC_MakePlane(mod, "GC_MakePlane", "This class implements the following algorithms used to create a Plane from gp. * Create a Plane parallel to another and passing through a point. * Create a Plane passing through 3 points. * Create a Plane by its normal A MakePlane object provides a framework for: - defining the construction of the plane, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed plane.");

// Constructors
cls_GC_MakePlane.def(py::init<const gp_Pln &>(), py::arg("Pl"));
cls_GC_MakePlane.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));
cls_GC_MakePlane.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_GC_MakePlane.def(py::init<const gp_Pln &, const gp_Pnt &>(), py::arg("Pln"), py::arg("Point"));
cls_GC_MakePlane.def(py::init<const gp_Pln &, const Standard_Real>(), py::arg("Pln"), py::arg("Dist"));
cls_GC_MakePlane.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_GC_MakePlane.def(py::init<const gp_Ax1 &>(), py::arg("Axis"));

// Methods
// cls_GC_MakePlane.def_static("operator new_", (void * (*)(size_t)) &GC_MakePlane::operator new, "None", py::arg("theSize"));
// cls_GC_MakePlane.def_static("operator delete_", (void (*)(void *)) &GC_MakePlane::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakePlane.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakePlane::operator new[], "None", py::arg("theSize"));
// cls_GC_MakePlane.def_static("operator delete[]_", (void (*)(void *)) &GC_MakePlane::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakePlane.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakePlane::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakePlane.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakePlane::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakePlane.def("Value", (const opencascade::handle<Geom_Plane> & (GC_MakePlane::*)() const) &GC_MakePlane::Value, "Returns the constructed plane. Exceptions StdFail_NotDone if no plane is constructed.");

// CLASS: GC_MAKEROTATION
py::class_<GC_MakeRotation> cls_GC_MakeRotation(mod, "GC_MakeRotation", "This class implements elementary construction algorithms for a rotation in 3D space. The result is a Geom_Transformation transformation. A MakeRotation object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_GC_MakeRotation.def(py::init<const gp_Lin &, const Standard_Real>(), py::arg("Line"), py::arg("Angle"));
cls_GC_MakeRotation.def(py::init<const gp_Ax1 &, const Standard_Real>(), py::arg("Axis"), py::arg("Angle"));
cls_GC_MakeRotation.def(py::init<const gp_Pnt &, const gp_Dir &, const Standard_Real>(), py::arg("Point"), py::arg("Direc"), py::arg("Angle"));

// Methods
// cls_GC_MakeRotation.def_static("operator new_", (void * (*)(size_t)) &GC_MakeRotation::operator new, "None", py::arg("theSize"));
// cls_GC_MakeRotation.def_static("operator delete_", (void (*)(void *)) &GC_MakeRotation::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeRotation.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeRotation::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeRotation.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeRotation::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeRotation.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeRotation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeRotation.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeRotation::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeRotation.def("Value", (const opencascade::handle<Geom_Transformation> & (GC_MakeRotation::*)() const) &GC_MakeRotation::Value, "Returns the constructed transformation.");

// CLASS: GC_MAKESCALE
py::class_<GC_MakeScale> cls_GC_MakeScale(mod, "GC_MakeScale", "This class implements an elementary construction algorithm for a scaling transformation in 3D space. The result is a Geom_Transformation transformation (a scaling transformation with the center point <Point> and the scaling value <Scale>). A MakeScale object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_GC_MakeScale.def(py::init<const gp_Pnt &, const Standard_Real>(), py::arg("Point"), py::arg("Scale"));

// Methods
// cls_GC_MakeScale.def_static("operator new_", (void * (*)(size_t)) &GC_MakeScale::operator new, "None", py::arg("theSize"));
// cls_GC_MakeScale.def_static("operator delete_", (void (*)(void *)) &GC_MakeScale::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeScale.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeScale::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeScale.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeScale::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeScale.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeScale::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeScale.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeScale::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeScale.def("Value", (const opencascade::handle<Geom_Transformation> & (GC_MakeScale::*)() const) &GC_MakeScale::Value, "Returns the constructed transformation.");

// CLASS: GC_MAKESEGMENT
py::class_<GC_MakeSegment, GC_Root> cls_GC_MakeSegment(mod, "GC_MakeSegment", "Implements construction algorithms for a line segment in 3D space. Makes a segment of Line from the 2 points <P1> and <P2>. The result is a Geom_TrimmedCurve curve. A MakeSegment object provides a framework for: - defining the construction of the line segment, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed line segment.");

// Constructors
cls_GC_MakeSegment.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
cls_GC_MakeSegment.def(py::init<const gp_Lin &, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("U1"), py::arg("U2"));
cls_GC_MakeSegment.def(py::init<const gp_Lin &, const gp_Pnt &, const Standard_Real>(), py::arg("Line"), py::arg("Point"), py::arg("Ulast"));
cls_GC_MakeSegment.def(py::init<const gp_Lin &, const gp_Pnt &, const gp_Pnt &>(), py::arg("Line"), py::arg("P1"), py::arg("P2"));

// Methods
// cls_GC_MakeSegment.def_static("operator new_", (void * (*)(size_t)) &GC_MakeSegment::operator new, "None", py::arg("theSize"));
// cls_GC_MakeSegment.def_static("operator delete_", (void (*)(void *)) &GC_MakeSegment::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeSegment.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeSegment::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeSegment.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeSegment::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeSegment.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeSegment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeSegment.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeSegment::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeSegment.def("Value", (const opencascade::handle<Geom_TrimmedCurve> & (GC_MakeSegment::*)() const) &GC_MakeSegment::Value, "Returns the constructed line segment.");

// CLASS: GC_MAKETRANSLATION
py::class_<GC_MakeTranslation> cls_GC_MakeTranslation(mod, "GC_MakeTranslation", "This class implements elementary construction algorithms for a translation in 3D space. The result is a Geom_Transformation transformation. A MakeTranslation object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_GC_MakeTranslation.def(py::init<const gp_Vec &>(), py::arg("Vect"));
cls_GC_MakeTranslation.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("Point1"), py::arg("Point2"));

// Methods
// cls_GC_MakeTranslation.def_static("operator new_", (void * (*)(size_t)) &GC_MakeTranslation::operator new, "None", py::arg("theSize"));
// cls_GC_MakeTranslation.def_static("operator delete_", (void (*)(void *)) &GC_MakeTranslation::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeTranslation.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeTranslation::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeTranslation.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeTranslation::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeTranslation.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeTranslation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeTranslation.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeTranslation::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeTranslation.def("Value", (const opencascade::handle<Geom_Transformation> & (GC_MakeTranslation::*)() const) &GC_MakeTranslation::Value, "Returns the constructed transformation.");

// CLASS: GC_MAKETRIMMEDCONE
py::class_<GC_MakeTrimmedCone, GC_Root> cls_GC_MakeTrimmedCone(mod, "GC_MakeTrimmedCone", "Implements construction algorithms for a trimmed cone limited by two planes orthogonal to its axis. The result is a Geom_RectangularTrimmedSurface surface. A MakeTrimmedCone provides a framework for: - defining the construction of the trimmed cone, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed trimmed cone.");

// Constructors
cls_GC_MakeTrimmedCone.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_GC_MakeTrimmedCone.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("R1"), py::arg("R2"));

// Methods
// cls_GC_MakeTrimmedCone.def_static("operator new_", (void * (*)(size_t)) &GC_MakeTrimmedCone::operator new, "None", py::arg("theSize"));
// cls_GC_MakeTrimmedCone.def_static("operator delete_", (void (*)(void *)) &GC_MakeTrimmedCone::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeTrimmedCone.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeTrimmedCone::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeTrimmedCone.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeTrimmedCone::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeTrimmedCone.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeTrimmedCone::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeTrimmedCone.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeTrimmedCone::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeTrimmedCone.def("Value", (const opencascade::handle<Geom_RectangularTrimmedSurface> & (GC_MakeTrimmedCone::*)() const) &GC_MakeTrimmedCone::Value, "Returns the constructed trimmed cone. StdFail_NotDone if no trimmed cone is constructed.");

// CLASS: GC_MAKETRIMMEDCYLINDER
py::class_<GC_MakeTrimmedCylinder, GC_Root> cls_GC_MakeTrimmedCylinder(mod, "GC_MakeTrimmedCylinder", "Implements construction algorithms for a trimmed cylinder limited by two planes orthogonal to its axis. The result is a Geom_RectangularTrimmedSurface surface. A MakeTrimmedCylinder provides a framework for: - defining the construction of the trimmed cylinder, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed trimmed cylinder.");

// Constructors
cls_GC_MakeTrimmedCylinder.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_GC_MakeTrimmedCylinder.def(py::init<const gp_Circ &, const Standard_Real>(), py::arg("Circ"), py::arg("Height"));
cls_GC_MakeTrimmedCylinder.def(py::init<const gp_Ax1 &, const Standard_Real, const Standard_Real>(), py::arg("A1"), py::arg("Radius"), py::arg("Height"));

// Methods
// cls_GC_MakeTrimmedCylinder.def_static("operator new_", (void * (*)(size_t)) &GC_MakeTrimmedCylinder::operator new, "None", py::arg("theSize"));
// cls_GC_MakeTrimmedCylinder.def_static("operator delete_", (void (*)(void *)) &GC_MakeTrimmedCylinder::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeTrimmedCylinder.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeTrimmedCylinder::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeTrimmedCylinder.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeTrimmedCylinder::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeTrimmedCylinder.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeTrimmedCylinder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeTrimmedCylinder.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeTrimmedCylinder::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeTrimmedCylinder.def("Value", (const opencascade::handle<Geom_RectangularTrimmedSurface> & (GC_MakeTrimmedCylinder::*)() const) &GC_MakeTrimmedCylinder::Value, "Returns the constructed trimmed cylinder. Exceptions StdFail_NotDone if no trimmed cylinder is constructed.");


}
