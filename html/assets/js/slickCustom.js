$(document).ready(function () {
    // $('.corporate__ticker').slick({
    //   vertical: true,
    //   slidesToShow: 3,
    //   slidesToScroll: 1,
    //   autoplay: true,
    //   autoplaySpeed: 2000,
    //   arrows: false,
    //   lazyLoad: 'progressive',
    // });
    // $('.notices__ticker').slick({
    //   vertical: true,
    //   slidesToShow: 3,
    //   slidesToScroll: 1,
    //   autoplay: true,
    //   autoplaySpeed: 2000,
    //   arrows: false,
    //   lazyLoad: 'progressive',
    // });

    // $('.slider__wrap').slick({
    //   slidesToShow: 1,
    //   slidesToScroll: 1,
    //   autoplay: true,
    //   autoplaySpeed: 2000,
    //   appendDots: '.slider__item--dots',
    //   arrows: false,
    //   dots: true,
    //   infinite: true,
    //   lazyLoad: 'progressive',
    // });
    
    $("#index__more").on('click', function(e){
      e.preventDefault();
      $('.index__chart').toggleClass('move');
      $('.index__subindices').toggleClass('show');
    });

    $('.index__subindices--overlay').on('click', function(e){
      $('.index__chart').removeClass('move');
      $('.index__subindices').removeClass('show');
    });
  });