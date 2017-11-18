#ifndef __Prs3d_Templates_Header__
#define __Prs3d_Templates_Header__

#include <pyOCCT_Common.hpp>

#include <Standard_Handle.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Drawer.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_Point.hxx>

// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_Point.hxx
template <typename AnyPoint, typename PointTool>
void bind_Prs3d_Point(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_Point.hxx
	py::class_<Prs3d_Point<AnyPoint, PointTool>, std::unique_ptr<Prs3d_Point<AnyPoint, PointTool>, Deleter<Prs3d_Point<AnyPoint, PointTool>>>> cls(mod, name.c_str(), "None");
	cls.def(py::init<>());
	cls.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const AnyPoint &, const opencascade::handle<Prs3d_Drawer> &)) &Prs3d_Point<AnyPoint, PointTool>::Add, "None", py::arg("thePresentation"), py::arg("thePoint"), py::arg("theDrawer"));
	cls.def_static("Match_", (Standard_Boolean (*)(const AnyPoint &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Prs3d_Point<AnyPoint, PointTool>::Match, "None", py::arg("thePoint"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDistance"));

};

#endif